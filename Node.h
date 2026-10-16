#ifndef NODE_H
#define NODE_H

#include <string>
#include <sstream>

class Node
{
public:
    // CONSTRUCTOR

    // CONST MEMBER FUNCTIONS
    virtual double evaluate() const = 0;
    virtual std::string postfix() const = 0;
    virtual std::string infix() const = 0;
    virtual std::string prefix() const = 0;

    // SPECIAL MEMBER FUNCTIONS
    virtual ~Node() = default;

};

#endif