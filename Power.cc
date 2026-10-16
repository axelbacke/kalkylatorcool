#include "Power.h"
#include <cmath>
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
Power::Power(Node* left, Node* right)
    : Operator{left, right}
{}

// SPECIAL MEMBER FUNCTIONS:

// PRIVATE MEMBER FUNCTIONS:

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:
double Power::evaluate() const
{
    double rightVal {right->evaluate()};
    double leftVal {left->evaluate()};
    if (leftVal < 0 && (fmod(rightVal, 1) != 0.0)) throw logic_error("DOMAIN ERROR");
    else if (leftVal == 0 && rightVal < 0) throw logic_error("DOMAIN ERROR");
    else return pow(leftVal, rightVal);
}

char Power::symbol() const
{
    return '^';
}
//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------