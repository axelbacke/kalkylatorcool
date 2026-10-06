#include "Addition.h"


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
Addition::Addition(Node* left, Node* right)
    : Operator{left, right}
{
}

// SPECIAL MEMBER FUNCTIONS:

// PRIVATE MEMBER FUNCTIONS:

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:
double Addition::evaluate() const
{
    return (left->evaluate() + right->evaluate());
}

string Addition::postfix() const
{
    stringstream ss {};
    ss << left->postfix() + " " + right->postfix() + " +";
    return ss.str();
}

//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------