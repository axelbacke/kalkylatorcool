#ifndef INTEGER_H
#define INTEGER_H

#include "Operand.h"

class Integer : public Operand
{
public:
    // CONSTRUCTORS.
    Integer(int const value);
    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;
    std::string postfix() const override;
    // NON-CONST MEMBER FUNCTIONS.

private:
    int value;
};

#endif