#ifndef OPERATOR_H
#define OPERATOR_H

#include "Node.h"

class Operator : public Node
{
public:
    // SPECIAL MEMBER FUNCTIONS.
    Operator(Operator const&) = delete;
    Operator& operator=(Operator const&) = delete;
    
    // CONST MEMBER FUNCTIONS.
    std::string postfix() const override;

    // NON-CONST MEMBER FUNCTIONS.
protected:
    // CONSTRUCTOR
    Operator(Node* l, Node* r);

    virtual char symbol() const = 0;

    Node* left;
    Node* right;
private:

};

#endif