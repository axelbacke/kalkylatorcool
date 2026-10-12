#include "Expression.h"
#include <iostream>

using namespace std;

int main()
{
  string line {};

  while ( getline(cin, line) )
  {
    try
    {
        Expression e{line};
        cout << e.toString() << endl
             << e.evaluate() << endl;
    }
    catch (exception& e)
    {
        cout << "Error of type: " << e.what() << endl;
    }
  }
  return 0;
}