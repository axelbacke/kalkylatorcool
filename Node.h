#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
public:
    // CONSTRUCTOR

    // CONST MEMBER FUNCTIONS
    virtual double evaluate() const = 0;
    virtual std::string postfix() const = 0;

    // SPECIAL MEMBER FUNCTIONS
    virtual ~Node() = default;

protected:
    // ERROR MESSAGES
    void throwSyntaxError() const;
    void throwBaseError() const;
    void throwValueError() const;
    void throwOverflowError() const;
    void throwUnderflowError() const;

private:

};

#endif