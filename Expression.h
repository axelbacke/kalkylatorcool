#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Node.h"

class Expression
{
public:
    // CONSTRUCTORS.
    Expression(std::string const& infix);
    // SPECIAL MEMBER FUNCTIONS.
    Expression(Expression const&) = delete;
    Expression& operator=(Expression const&) = delete;

    Expression(Expression && other);
    Expression& operator=(Expression && rhs);

    // CONST MEMBER FUNCTIONS.
    std::string toInfix() const;
    std::string toPrefix() const;
    std::string toPostfix() const;
    double evaluate() const;
    // NON-CONST MEMBER FUNCTIONS.
protected:
private:
    Node* root;

};

#endif