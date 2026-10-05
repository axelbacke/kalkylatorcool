#include "Integer.h"


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
Integer::Integer(int const val)
    : value {val}
{}

Integer::Integer()
    : value {0}
{
    throwSyntaxError();
}

// SPECIAL MEMBER FUNCTIONS:

// PRIVATE MEMBER FUNCTIONS:

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:
double Integer::evaluate() const
{
    return double {value};
}

string Integer::postfix() const
{
    return "   ";
}
//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------