#include "Division.h"
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
Division::Division(Node* left, Node* right)
    : Operator{left, right}
{}

// SPECIAL MEMBER FUNCTIONS:

// PRIVATE MEMBER FUNCTIONS:

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:
double Division::evaluate() const
{
    double rightVal = right->evaluate();
    if (rightVal == 0) throw logic_error("DIVSION BY ZERO ERROR");
    else return left->evaluate() / rightVal;
}

char Division::symbol() const
{
    return '/';
}
//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------