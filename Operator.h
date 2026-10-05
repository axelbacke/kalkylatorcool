#ifndef OPERATOR_H
#define OPERATOR_H

class Operator : public Node
{
public:
    // CONSTRUCTORS.
    Operator(Node* l, Node* r);

    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.

    // NON-CONST MEMBER FUNCTIONS.
protected:
    Node* left;
    Node* right;
private:

}

#endif