#ifndef REAL_H
#define REAL_H

<<<<<<< HEAD
#include "Operand.h"

=======
>>>>>>> 9353490 (First commit of Real.h and Integer.h class)
class Real : public Operand
{
public:
    // CONSTRUCTORS.
<<<<<<< HEAD
    Real(double const val);
    Real(std::string const& str);
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
=======
    Real();
    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;
    // NON-CONST MEMBER FUNCTIONS.
protected:
private:

}
>>>>>>> 9353490 (First commit of Real.h and Integer.h class)

#endif