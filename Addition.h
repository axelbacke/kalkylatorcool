#ifndef ADDITION_H
#define ADDITION_H

class Addition : public Operator
{
public:
    // CONSTRUCTORS.
    Addition();

    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;

    // NON-CONST MEMBER FUNCTIONS.
protected:
private:

}

#endif