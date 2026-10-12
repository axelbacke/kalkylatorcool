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
        
        Node* nodePtr {nullptr};
        Node* left {nullptr};
        Node* right {nullptr};
        stack<Node*> nodeStack {};

        string word {};
        while(iss >> word)
        {
            // Nedan är långt från ``foolproof'', men du behöver inte göra
            // mer kontroller än detta för att skilja ut olika operander.
            if ( std::all_of( begin(word), end(word), ::isdigit ) )
            {
                // Vi har hittat ett heltal
                nodeStack.push(new Integer{word});
            }
            else if ( isdigit(word.at(0)) )
            {
                // Vi hoppas ordet är ett flyttal
                try
                {
                    nodeStack.push(new Real{word});
                }
                
                catch (...)
                {
                    throw logic_error("INVALID INPUT");
                }
            }
            else
            {
                // Vi hoppas ordet är en operator
                
                // CHECK SIZE OF STACK; SHOULD BE 2.

                if (nodeStack.size() < 2) throw logic_error("MISSING OPERAND ERROR"); 
                right = nodeStack.top();
                nodeStack.pop();
                
                left = nodeStack.top();
                nodeStack.pop();

                if (word == "+") nodeStack.push(new Addition{left, right});
                else if (word == "-") nodeStack.push(new Subtraction{left, right});
                else if (word == "*") nodeStack.push(new Multiplication{left, right});
                else if (word == "/") nodeStack.push(new Division{left, right});
                else if (word == "^") nodeStack.push(new Power{left, right});

                else throw logic_error("INVALID INPUT: " + word);
                
            }
        }
        if (nodeStack.size() > 1) throw logic_error("MISSING OPERATOR ERROR");
        else if (nodeStack.size() == 0) throw logic_error("EMPTY INPUT ERROR");
        root = nodeStack.top();
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
// PRIVATE MEMBER FUNCTIONS:

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:
string Expression::toInfix() const
{
    return root->infix();
}

string Expression::toPrefix() const
{
    return root->prefix();
}

string Expression::toPostfix() const
{
    return root->postfix();
}

double Expression::evaluate() const
{
    return root->evaluate();
}
//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------