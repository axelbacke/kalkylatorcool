#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
public:
    // CONSTRUCTOR
    Node();

    // CONST MEMBER FUNCTIONS
    virtual double evaluate() const;
    virtual std::string postfix() const;

    // SPECIAL MEMBER FUNCTIONS

protected:
private:

}

#endif