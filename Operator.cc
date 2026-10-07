#include "Operator.h"

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
Operator::Operator(Node* l, Node* r)
    : left {l}, right {r}
{}

// SPECIAL MEMBER FUNCTIONS:

// PRIVATE MEMBER FUNCTIONS:

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:
string Operator::postfix() const
{   
    stringstream ss {};
    ss << left->postfix() << ' ' << right->postfix() << ' ' << symbol();
    return ss.str();
}

string Operator::infix() const
{
    stringstream ss {};
    ss << "( " << left->infix() << ' ' << symbol() << ' ' << right->infix() << " )";
    return ss.str();
}
string Operator::prefix() const
{
    stringstream ss {};
    ss << symbol() << ' ' << left->prefix() << ' ' << right->prefix();
    return ss.str();
}

//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------