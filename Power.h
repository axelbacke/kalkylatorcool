#ifndef POWER_H
#define POWER_H

#include "Operator.h"

class Power : public Operator
{
public:
    // CONSTRUCTORS.
    Power(Node* left, Node* right);

    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;

    // NON-CONST MEMBER FUNCTIONS.
protected:
    char symbol() const override;

};

#endif