#ifndef DIVISION_H
#define DIVISION_H

#include "Operator.h"

class Division : public Operator
{
public:
    // CONSTRUCTORS.
    Division(Node* left, Node* right);

    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;

    // NON-CONST MEMBER FUNCTIONS.
protected:
    char symbol() const override;
private:

};

#endif