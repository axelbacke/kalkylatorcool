#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "Operator.h"

class Subtraction : public Operator
{
public:
    // CONSTRUCTORS.
    Subtraction(Node* left, Node* right);

    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;

    // NON-CONST MEMBER FUNCTIONS.
protected:
    std::string symbol() const override;

private:

};

#endif