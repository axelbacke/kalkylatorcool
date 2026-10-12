#include <limits>
#include <cmath> // abs
#include <memory>
//------------------------------------
#include "Addition.h"
#include "Subtraction.h"
#include "Real.h"
#include "Integer.h"
#include "Multiplication.h"
#include "Division.h"
#include "Power.h"
#include "Expression.h"
//------------------------------------
#include "catch.hpp"

bool compare_equal(double a, double b)
{
  return std::abs(a - b) <= 0.001; // only care about thosands in our calculations
}

TEST_CASE("Operand real")
{
  SECTION("String constructor")
  {
    Operand* pi{ new Real{"3.14"} };
    CHECK( pi->evaluate() == 3.14 );
    CHECK( pi->postfix() == "3.140" );
  }

  Operand* pi{ new Real{3.14} };

  CHECK( pi->evaluate() == 3.14 );
  CHECK( pi->postfix() == "3.140" );

  Operand* negPi{ new Real{-3.14} };

  CHECK( negPi->evaluate() == -3.14 );
  CHECK( negPi->postfix() == "-3.140" );

}

TEST_CASE("Operand integer")
{
  SECTION("String constructor")
  {
    Operand* integer{ new Integer{"300"} };
    CHECK( integer->evaluate() == 300 );
    CHECK( integer->postfix() == "300" );
  }
  Operand* ten{ new Integer{10} };

  CHECK( ten->evaluate() == 10 );
  CHECK( ten->postfix() == "10" );

  Operand* negTen{ new Integer{-10} };

  CHECK( negTen->evaluate() == -10 );
  CHECK( negTen->postfix() == "-10" );

}


TEST_CASE("Addition")
// TEST_CASE is like a loop doing one SECTION each iteration
// meaning we get a fresh "pi" and "e" for each section
{
  // Done each iteration of the TEST_CASE
  Node* pi = new Real{3.14};
  Node* e = new Real{2.72};

  SECTION("Commutative case pi+e") // Done the first iteration only
  {
    Node* plus = new Addition{pi, e};
    
    CHECK( plus->evaluate() == 5.86 );
    CHECK( plus->postfix() == "3.140 2.720 +" );
  }
  
  SECTION("Commutative case e+pi") // Done the second iteration only
  {
    Node* plus = new Addition{e, pi};

    CHECK( plus->evaluate() == 5.86 );
    CHECK( plus->postfix() == "2.720 3.140 +" );
  }

  // Note: reusing "pi" and "e" to create several Addition nodes will
  // make memory deallocation difficult, using SECTION to have a new
  // set of pi and e for each section solves this.
  // Doing the actual deallocation is your task once you have suitable
  // destructors.

  // -------------- ADDITIONAL TESTS ----------------

  SECTION("Two negative integers")
  {
    Node* a = new Integer{-4};
    Node* b = new Integer{-6};

    Node* plus = new Addition{a, b};

    CHECK(plus->evaluate() == -10);
    CHECK(plus->postfix() == "-4 -6 +");
  }

  SECTION("Positive integer + negative real")
  {
    Node* a = new Integer{10};
    Node* b = new Real{-3.1};

    Node* plus = new Addition{a, b};

    CHECK(plus->evaluate() == 6.9);
    CHECK(plus->postfix() == "10 -3.100 +");
  }

  SECTION("Addition with zero")
  {
    Node* a = new Integer{0};
    Node* b = new Integer{15};

    Node* plus = new Addition{a, b};

    CHECK(plus->evaluate() == 15);
    CHECK(plus->postfix() == "0 15 +");
  }
}


TEST_CASE("Subtraction")
{
  
  // Done each iteration of the TEST_CASE
  Node* pi = new Real{3.14};
  Node* e = new Real{2.72};

  SECTION("Subtraction case pi-e")
  {
    Node* sub = new Subtraction{pi, e};
    
    CHECK(compare_equal(sub->evaluate(), 0.42));
    CHECK(sub->postfix() == "3.140 2.720 -");
  }
  
  SECTION("Subtraction case e-pi")
  {
    Node* sub = new Subtraction{e, pi};

    CHECK(compare_equal(sub->evaluate(), -0.42));
    CHECK(sub->postfix() == "2.720 3.140 -");
  }

  SECTION("Two negative integers")
  {
    Node* a = new Integer{-4};
    Node* b = new Integer{-6};

    Node* sub = new Subtraction{a, b};

    CHECK(sub->evaluate() == 2);
    CHECK(sub->postfix() == "-4 -6 -");
  }

  SECTION("Positive integer - negative real")
  {
    Node* a = new Integer{10};
    Node* b = new Real{-3.1};

    Node* sub = new Subtraction{a, b};

    CHECK(sub->evaluate() == 13.1);
    CHECK(sub->postfix() == "10 -3.100 -");
  }

  SECTION("Subtraction with zero")
  {
    Node* a = new Integer{15};
    Node* b = new Integer{0};

    Node* sub = new Subtraction{a, b};

    CHECK(sub->evaluate() == 15);
    CHECK(sub->postfix() == "15 0 -");
  }
}


TEST_CASE("Multiplication")
{
  
  // Done each iteration of the TEST_CASE
  Node* pi = new Real{3.14};
  Node* e = new Real{2.72};

  SECTION("Multiplication case pi*e")
  {
    Node* multi = new Multiplication{pi, e};
    
    CHECK(compare_equal(multi->evaluate(), 8.5408));
    CHECK(multi->postfix() == "3.140 2.720 *");
  }
  
  SECTION("Multiplication case e*pi")
  {
    Node* multi = new Multiplication{e, pi};

    CHECK(compare_equal(multi->evaluate(), 8.5408));
    CHECK(multi->postfix() == "2.720 3.140 *");
  }

  SECTION("Two negative integers")
  {
    Node* a = new Integer{-4};
    Node* b = new Integer{-6};

    Node* multi = new Multiplication{a, b};

    CHECK(multi->evaluate() == 24);
    CHECK(multi->postfix() == "-4 -6 *");
  }

  SECTION("Positive integer * negative real")
  {
    Node* a = new Integer{10};
    Node* b = new Real{-3.1};

    Node* multi = new Multiplication{a, b};

    CHECK(multi->evaluate() == -31);
    CHECK(multi->postfix() == "10 -3.100 *");
  }

  SECTION("Multiplication with zero")
  {
    Node* a = new Integer{15};
    Node* b = new Integer{0};

    Node* multi = new Multiplication{a, b};

    CHECK(multi->evaluate() == 0);
    CHECK(multi->postfix() == "15 0 *");
  }

  SECTION("Multiplication with close to zero")
  {
    Node* a = new Integer{15};
    Node* b = new Real{0.001};

    Node* multi = new Multiplication{a, b};

    CHECK(multi->evaluate() == 0.015);
    CHECK(multi->postfix() == "15 0.001 *");
  }
}

TEST_CASE("Division")
{
  
  // Done each iteration of the TEST_CASE
  Node* pi = new Real{3.14};
  Node* e = new Real{2.72};

  SECTION("Division case pi*e")
  {
    Node* div = new Division{pi, e};
    
    CHECK(compare_equal(div->evaluate(), 1.154411765));
    CHECK(div->postfix() == "3.140 2.720 /");
  }
  
  SECTION("Division case e*pi")
  {
    Node* div = new Division{e, pi};

    CHECK(compare_equal(div->evaluate(), 0.866242038));
    CHECK(div->postfix() == "2.720 3.140 /");
  }

  SECTION("Two negative integers")
  {
    Node* a = new Integer{-4};
    Node* b = new Integer{-6};

    Node* div = new Division{a, b};

    CHECK(compare_equal(div->evaluate(), 0.66666667));
    CHECK(div->postfix() == "-4 -6 /");
  }

  SECTION("Positive integer * negative real")
  {
    Node* a = new Integer{10};
    Node* b = new Real{-3.1};

    Node* div = new Division{a, b};

    CHECK(compare_equal(div->evaluate(), -3.225806452));
    CHECK(div->postfix() == "10 -3.100 /");
  }

  SECTION("Division with integer zero")
  {
    Node* a = new Integer{15};
    Node* b = new Integer{0};

    Node* div = new Division{a, b};

    CHECK_THROWS(div->evaluate());
    CHECK(div->postfix() == "15 0 /");
  }

  SECTION("Division with real zero")
  {
    Node* a = new Integer{15};
    Node* b = new Real{0.0};

    Node* div = new Division{a, b};

    CHECK_THROWS(div->evaluate());
    CHECK(div->postfix() == "15 0.000 /");
  }

  SECTION("Divide int zero by real zero")
  {
    Node* a = new Integer{0};
    Node* b = new Real{0.0};

    Node* div = new Division{a, b};

    CHECK_THROWS(div->evaluate());
    CHECK(div->postfix() == "0 0.000 /");
  }
  
  SECTION("Divide real zero by int zero")
  {
    Node* a = new Integer{0};
    Node* b = new Real{0.0};

    Node* div = new Division{b, a};

    CHECK_THROWS(div->evaluate());
    CHECK(div->postfix() == "0.000 0 /");
  }
  
  SECTION("Divide int zero by int zero")
  {
    Node* a = new Integer{0};
    Node* b = new Integer{0};

    Node* div = new Division{a, b};

    CHECK_THROWS(div->evaluate());
    CHECK(div->postfix() == "0 0 /");
  }
  
  SECTION("Divide real zero by real zero")
  {
    Node* a = new Real{0.0};
    Node* b = new Real{0.0};

    Node* div = new Division{a, b};

    CHECK_THROWS(div->evaluate());
    CHECK(div->postfix() == "0.000 0.000 /");
  }
}

TEST_CASE("Power")
{
  
  // Done each iteration of the TEST_CASE
  Node* pi = new Real{3.14};
  Node* e = new Real{2.72};

  SECTION("Power case pi^e")
  {
    Node* pow = new Power{pi, e};
    
    CHECK(compare_equal(pow->evaluate(), 22.47235789));
    CHECK(pow->postfix() == "3.140 2.720 ^");
  }
  
  SECTION("Power case e^pi")
  {
    Node* pow = new Power{e, pi};

    CHECK(compare_equal(pow->evaluate(), 23.14975284));
    CHECK(pow->postfix() == "2.720 3.140 ^");
  }

  SECTION("Two negative integers")
  {
    Node* a = new Integer{-4};
    Node* b = new Integer{-6};

    Node* pow = new Power{a, b};

    CHECK(compare_equal(pow->evaluate(), 0.000244141));
    CHECK(pow->postfix() == "-4 -6 ^");
  }

  SECTION("Positive integer ^ negative real")
  {
    Node* a = new Integer{10};
    Node* b = new Real{-3.1};

    Node* pow = new Power{a, b};

    CHECK(compare_equal(pow->evaluate(), 0.000794328));
    CHECK(pow->postfix() == "10 -3.100 ^");
  }

  SECTION("Negative number ^ real")
  {
    Node* a = new Integer{-10};
    Node* b = new Real{3.1};
    Node* c = new Real{-3.1};

    Node* pow1 = new Power{a, b};
    Node* pow2 = new Power{a, c};

    CHECK_THROWS(pow1->evaluate());
    CHECK_THROWS(pow2->evaluate());
  }

  SECTION("Power with zero")
  {
    Node* a = new Integer{15};
    Node* b = new Integer{0};

    Node* pow = new Power{a, b};

    CHECK(pow->evaluate() == 1);
    CHECK(pow->postfix() == "15 0 ^");
  }

  SECTION("0 ^ negative number")
  {
    Node* a = new Integer{0};
    Node* b = new Integer{-15};

    Node* pow = new Power{a, b};

    CHECK_THROWS(pow->evaluate());
    CHECK(pow->postfix() == "0 -15 ^");
  }
}

TEST_CASE("Test case ignoring rounding errors")
{
  Node* a = new Real{0.01};
  Node* b = new Real{0.09};
  
  SECTION("Testing add with rounding error")
  {
    Node* plus = new Addition{a, b};

    // abs() exists in several versions, a bad combination of includes
    // and namespaces will land you in the old C-version for integers
    // without any warning, we test for this!
    CHECK( std::abs(-0.1) == 0.1 ); // make sure we use floating point "abs"
    
    // CHECK( plus->evaluate() == 0.1 ); // Rounding error!!
    CHECK( compare_equal(plus->evaluate(), 0.1) );
  }
}

TEST_CASE("Nested operator")
{
  Node* s = new Subtraction(new Real{3.0}, new Integer{1});
  Node* m = new Multiplication(new Integer{2}, new Integer{5});
  
  SECTION("Doubly nested")
  {
    Node* a = new Addition(s, m);

    CHECK(a->evaluate() == 12);
    CHECK(a->postfix() == "3.000 1 - 2 5 * +");
  }

  SECTION("Triply (?) nested")
  {
    Node* a = new Division(new Addition(s, m), new Multiplication(s, m));

    CHECK(a->evaluate() == 0.6);
    CHECK(a->postfix() == "3.000 1 - 2 5 * + 3.000 1 - 2 5 * * /");
  }

  SECTION("Check nested division error")
  {
    Node* a = new Division(new Multiplication(new Integer{2}, new Integer{1}), 
                           new Addition(new Integer{1}, new Integer{-1})
                          );
    CHECK_THROWS(a->evaluate());
    CHECK(a->postfix() == "2 1 * 1 -1 + /");
  }


}

TEST_CASE("Conversion to string")
{
  Node* s = new Subtraction(new Real{1.0}, new Integer{1});
  Node* m = new Multiplication(new Integer{2}, new Integer{5});
  Node* a = new Addition(s, m);

  SECTION("Postfix")
  {
    CHECK(a->postfix() == "1.000 1 - 2 5 * +");
  }
  SECTION("Infix")
  {
    CHECK(a->infix() == "( ( 1.000 - 1 ) + ( 2 * 5 ) )");
  }
  SECTION("Prefix")
  {
    CHECK(a->prefix() == "+ - 1.000 1 * 2 5");
  }
}


TEST_CASE("Expression")
{
  SECTION("Constructor")
  {
    CHECK_THROWS(Expression{""});

    Expression e {"+ 3 4"};
    CHECK(e.toInfix() == "( 3 + 4 )");
    CHECK(e.evaluate() == 7);

    Expression e1 {"+ - 4 7 * 3 4"};
    CHECK(e1.toInfix() == "( 4 - 7 ) + ( 3 * 4 )");
    CHECK(e1.evaluate() == 9);

    Expression e2 {"/ 7 0"};
  }
  SECTION("toInfix")
  {
    Expression e1 {"- ^ * 0 3 7 + 4 3"};
    CHECK(e1.toInfix() == "( ( 0 * 3 ) ^ 7 ) - ( 4 + 3 )")

    Expression e2 {"/ 7 0"};
    CHECK(e2.toInfix() == "( 7 / 0 )");
  }
  SECTION("evaluate")
  {
    Expression e1 {"- ^ * 0 3 7 + 4 3"};
    CHECK(e1.evaluate() == -7);

    Expression e2 {"/ 7 0"};
    CHECK_THROWS(e2.evaluate());
  }
}
