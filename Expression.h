#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Node.h"

class Expression
{
public:
    // CONSTRUCTORS.
    Expression(std::string const& infix);
    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    std::string toString() const;
    double evaluate() const;
    // NON-CONST MEMBER FUNCTIONS.
protected:
private:
    Node* root;

};

#endif