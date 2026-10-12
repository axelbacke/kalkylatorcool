#include "Expression.h"
#include <iostream>

using namespace std;

int main()
{
  string line {};
  while ( getline(cin, line) )
  {
    Expression e{line};
    cout << e.toString() << endl
         << e.evaluate() << endl;
  }
  return 0;
}