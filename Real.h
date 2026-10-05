#ifndef REAL_H
#define REAL_H

class Real : public Operand
{
public:
    // CONSTRUCTORS.
    Real();
    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;
    // NON-CONST MEMBER FUNCTIONS.
protected:
private:

}

#endif