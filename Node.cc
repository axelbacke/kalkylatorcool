#include "Node.h"
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

// SPECIAL MEMBER FUNCTIONS:

// PRIVATE MEMBER FUNCTIONS:

// NON-CONST MEMBER FUNCTIONS:

// CONST MEMBER FUNCTIONS:

void Node::throwSyntaxError() const
{
    throw logic_error("SYNTAX ERROR");
}
void Node::throwBaseError() const
{
    throw logic_error("BASE ERROR");
}
void Node::throwValueError() const
{
    throw invalid_argument("VALUE ERROR");
}
void Node::throwOverflowError() const
{
    throw overflow_error("OVERFLOW ERROR");
}
void Node::throwUnderflowError() const
{
    throw underflow_error("UNDERFLOW ERROR");
}
//--------------------------------------------------
// END OF MEMBER FUNCTIONS -------------------------
//--------------------------------------------------