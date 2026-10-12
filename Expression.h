#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Node.h"

class Expression
{
public:
    // CONSTRUCTORS.
    Expression(std::string const& postfix);
    // SPECIAL MEMBER FUNCTIONS.

    // CONST MEMBER FUNCTIONS.
    std::string toInfix() const;
    double evaluate() const;
    // NON-CONST MEMBER FUNCTIONS.
protected:
private:
    Node* root;

};

#endif