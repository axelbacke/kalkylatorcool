#ifndef INTEGER_H
#define INTEGER_H

class Integer : public Operand
{
public:
    // CONSTRUCTORS.
    Integer();
    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;
    // NON-CONST MEMBER FUNCTIONS.
protected:
private:

}

#endif