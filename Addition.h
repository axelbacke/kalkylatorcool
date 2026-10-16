#ifndef ADDITION_H
#define ADDITION_H

#include "Operator.h"

class Addition : public Operator
{
public:
    // CONSTRUCTORS.
    Addition(Node* left, Node* right);

    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;

    // NON-CONST MEMBER FUNCTIONS.
protected:
    char symbol() const override;

};

#endif