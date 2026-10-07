#ifndef REAL_H
#define REAL_H

#include "Operand.h"

class Real : public Operand
{
public:
    // CONSTRUCTORS.
    Real(double const val);
    // SPECIAL MEMBER FUNCTIONS.
    ~Real() = default;
    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;
    std::string postfix() const override;
    // NON-CONST MEMBER FUNCTIONS.
protected:
private:
    double value;

};

#endif