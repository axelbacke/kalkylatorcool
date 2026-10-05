#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
public:
    // CONSTRUCTOR

    // CONST MEMBER FUNCTIONS
    virtual double evaluate() const;
    virtual std::string postfix() const;

    // SPECIAL MEMBER FUNCTIONS
    virtual ~Node() = default;

protected:
private:

}

#endif