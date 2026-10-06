#include <limits>
#include <cmath> // abs
#include <memory>
//------------------------------------
#include "Addition.h"
#include "Subtraction.h"
#include "Real.h"
#include "Integer.h"
//------------------------------------
#include "catch.hpp"

bool compare_equal(double a, double b)
{
  return std::abs(a - b) <= 0.001; // only care about thosands in our calculations
}

TEST_CASE("Operand real")
{
  Operand* pi{ new Real{3.14} };

  CHECK( pi->evaluate() == 3.14 );
  CHECK( pi->postfix() == "3.140" );

  Operand* negPi{ new Real{-3.14} };

  CHECK( negPi->evaluate() == -3.14 );
  CHECK( negPi->postfix() == "-3.140" );

  // Throw error if no argument
  CHECK_THROWS(new Real{});
}

TEST_CASE("Operand integer")
{
  Operand* ten{ new Integer{10} };

  CHECK( ten->evaluate() == 10 );
  CHECK( ten->postfix() == "10" );

  Operand* negTen{ new Integer{-10} };

  CHECK( negTen->evaluate() == -10 );
  CHECK( negTen->postfix() == "-10" );

  // Throw error if no argument
  CHECK_THROWS(new Integer{});
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

#if 0 // Flytta ned denna rad fÃ¶r att aktivera nÃ¤sta TEST_CASE

TEST_CASE("Conversion to string")
{
    Node* a = new Addition{ new Subtraction{ new Real{1.0},
                                             new Integer{1} },
                            new Multiplication{ new Integer{2},
                                                new Integer{5} }
    };
    SECTION("Prefix")
    {
        CHECK( a->prefix() == "+ - 1.000 1 * 2 5" );
    }
    SECTION("Infix")
    {
        CHECK( a->infix() == "( ( 1.000 - 1 ) + ( 2 * 5 ) )" );
    }
    SECTION(">Postfix")
    {
        CHECK( a->postfix() == "1.000 1 - 2 5 * +" );
    }
}

#endif