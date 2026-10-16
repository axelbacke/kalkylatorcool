#include "Expression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Real.h"
#include "Integer.h"
#include "Multiplication.h"
#include "Division.h"
#include "Power.h"
#include "postfix.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stack>
#include <stdexcept>
#include <memory>

using namespace std;

//--------------------------------------------------
// NON-MEMBER FUNCTIONS ----------------------------
//--------------------------------------------------

//--------------------------------------------------
// END OF NON-MEMBER FUNCTIONS ---------------------
//--------------------------------------------------


//--------------------------------------------------
// MEMBER FUNCTIONS --------------------------------
//--------------------------------------------------

//CONSTRUCTOR:
Expression::Expression(string const& infix)
    : root {nullptr}
{
    if (infix != "")
    {
        Postfix postfix {infix};
        istringstream iss {postfix.to_string()};
        
        unique_ptr<Node> nodePtr {nullptr};
        unique_ptr<Node> left {nullptr};
        unique_ptr<Node> right {nullptr};
        stack<unique_ptr<Node>> nodeStack {};

        string word {};
        while(iss >> word)
        {
            // Nedan är långt från ``foolproof'', men du behöver inte göra
            // mer kontroller än detta för att skilja ut olika operander.
            if ( std::all_of( begin(word), end(word), ::isdigit ) )
            {
                // Vi har hittat ett heltal
                nodeStack.push(make_unique<Integer>(stoi(word)));
            }
            else if ( isdigit(word.at(0)) )
            {
                // Vi hoppas ordet är ett flyttal
                try
                {
                    nodeStack.push(make_unique<Real>(stof(word)));
                }
                
                catch (...)
                {
                    throw logic_error("INVALID INPUT: " + word);
                }
            }
            else
            {
                // Vi hoppas ordet är en operator
                
                // CHECK SIZE OF STACK; SHOULD BE 2.

                if (nodeStack.size() < 2) throw logic_error("MISSING OPERAND ERROR"); 
                right = std::move(nodeStack.top());
                nodeStack.pop();
                
                left = std::move(nodeStack.top());
                nodeStack.pop();

                if (word == "+") nodeStack.push(make_unique<Addition>(left.release(), right.release()));
                else if (word == "-") nodeStack.push(make_unique<Subtraction>(left.release(), right.release()));
                else if (word == "*") nodeStack.push(make_unique<Multiplication>(left.release(), right.release()));
                else if (word == "/") nodeStack.push(make_unique<Division>(left.release(), right.release()));
                else if (word == "^") nodeStack.push(make_unique<Power>(left.release(), right.release()));

                else throw logic_error("UNKNOWN OPERATOR: " + word);
                
            }
        }
        if (nodeStack.size() > 1) throw logic_error("MISSING OPERATOR ERROR");
        else if (nodeStack.size() == 0) throw logic_error("EMPTY INPUT ERROR");
        root = nodeStack.top().release();
    }

}
// SPECIAL MEMBER FUNCTIONS:
Expression::Expression(Expression && other)
    : root {other.root}
{
    other.root = nullptr;
}

Expression& Expression::operator=(Expression && rhs)
{
    std::swap(root, rhs.root);
    return *this;
}

Expression::~Expression()
{
    delete root;
}
// PRIVATE MEMBER FUNCTIONS:
void Expression::throwEmptyExpressionError() const
{
    if (root == nullptr) throw logic_error("EMPTY EXPRESSION");
}

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:
string Expression::toInfix() const
{
    throwEmptyExpressionError();
    return root->infix();
}

string Expression::toPrefix() const
{
    throwEmptyExpressionError();
    return root->prefix();
}

string Expression::toPostfix() const
{
    throwEmptyExpressionError();
    return root->postfix();
}

double Expression::evaluate() const
{
    throwEmptyExpressionError();
    return root->evaluate();
}
//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------