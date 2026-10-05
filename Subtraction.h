#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "Operator.h"

class Subtraction : public Operator
{
public:
    // CONSTRUCTORS.
    Subtraction();

    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;
    std::string postfix() const override;

    // NON-CONST MEMBER FUNCTIONS.
protected:
private:

};

#endif