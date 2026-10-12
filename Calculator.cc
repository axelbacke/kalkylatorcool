#include "Expression.h"
#include <iostream>

using namespace std;

int main()
{
  string line {};
  Expression e {""};

  while ( getline(cin, line) )
  {
    try
    {
        if (line.at(0) == ':')
        {
            if (line == ":prefix")
            {
                cout << e.toPrefix() << endl;
            }
            else if (line == ":infix")
            {
                cout << e.toInfix() << endl;
            } 
            else if (line == ":postfix")
            {
                cout << e.toPostfix() << endl;
            }
            else if (line == ":calc")
            {
                cout << e.evaluate() << endl;
            }
            else if (line == ":quit" || line == ":exit")
            {
                return 0;
            }
        }
        else
        {
            e = Expression {line};
        }
    }
    catch (exception& e)
    {
        cout << "Error of type: " << e.what() << endl;
    }
  }
  return 0;
}