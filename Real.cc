#include "Real.h"
#include <iomanip>

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
Real::Real (double const val)
    : value {val}
{}

Real::Real(string const& str)
    : value {}
{
    istringstream iss {str};
    iss >> value;
}
// SPECIAL MEMBER FUNCTIONS:

// PRIVATE MEMBER FUNCTIONS:

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:
double Real::evaluate() const
{
    return value;
}

string Real::postfix() const
{
    stringstream ss {};
    ss << fixed << setprecision(3) << value;
    return ss.str();
}

//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------