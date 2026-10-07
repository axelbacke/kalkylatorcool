#include "Operand.h"

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

// SPECIAL MEMBER FUNCTIONS:

// PRIVATE MEMBER FUNCTIONS:

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:
string Operand::infix() const
{
    return postfix();
}
string Operand::prefix() const
{
    return postfix();
}

//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------