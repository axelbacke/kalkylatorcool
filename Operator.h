#ifndef OPERATOR_H
#define OPERATOR_H

#include "Node.h"

class Operator : public Node
{
public:
    // SPECIAL MEMBER FUNCTIONS.
    
    // CONST MEMBER FUNCTIONS.
    std::string postfix() const override;

    // NON-CONST MEMBER FUNCTIONS.
protected:
    // CONSTRUCTOR
    Operator(Node* l, Node* r);

    virtual std::string symbol() const = 0;

    Node* left;
    Node* right;
private:

};

#endif