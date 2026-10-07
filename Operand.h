#ifndef OPERAND_H
#define OPERAND_H

#include "Node.h"


class Operand : public Node
{
public:
    // CONSTRUCTORS.
    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    std::string infix() const override;
    std::string prefix() const override;

    // NON-CONST MEMBER FUNCTIONS.
protected:
private:


};

#endif
