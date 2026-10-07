#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Operator.h"

class Multiplication : public Operator
{
public:
    // CONSTRUCTORS.
    Multiplication(Node* left, Node* right);

    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;

    // NON-CONST MEMBER FUNCTIONS.
protected:
    char symbol() const override;
private:

};

#endif