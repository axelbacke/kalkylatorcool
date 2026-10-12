#ifndef INTEGER_H
#define INTEGER_H

<<<<<<< HEAD
#include "Operand.h"

=======
>>>>>>> 9353490 (First commit of Real.h and Integer.h class)
class Integer : public Operand
{
public:
    // CONSTRUCTORS.
<<<<<<< HEAD
    Integer(int const value);
    Integer(std::string const& str);
=======
    Integer();
>>>>>>> 9353490 (First commit of Real.h and Integer.h class)
    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    double evaluate() const override;
<<<<<<< HEAD
    std::string postfix() const override;
    // NON-CONST MEMBER FUNCTIONS.
protected:
private:
    int value;
};
=======
    // NON-CONST MEMBER FUNCTIONS.
protected:
private:

}
>>>>>>> 9353490 (First commit of Real.h and Integer.h class)

#endif