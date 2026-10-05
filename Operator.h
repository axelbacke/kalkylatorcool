#ifndef OPERATOR_H
#define OPERATOR_H

#include "Node.h"

class Operator : public Node
{
public:
    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.

    // NON-CONST MEMBER FUNCTIONS.
protected:
    // CONSTRUCTOR
    Operator(Node* l, Node* r);

    Node* left;
    Node* right;
private:

};

#endif