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
    : Operator{Node* left, Node* right}
{

}

// SPECIAL MEMBER FUNCTIONS:

// PRIVATE MEMBER FUNCTIONS:

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:
double evaluate() const override
{
    return (left->evaluate() + left->evaluate());
}
std::string postfix() const override
{
    return "   ";
}

//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------