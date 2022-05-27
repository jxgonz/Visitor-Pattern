#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "gtest/gtest.h"
#include "visitor.hpp"
#include "VisitorLatex.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "div.hpp"
#include "pow.hpp"

TEST(VisitorLatexTest, LatexVisitsDiv) {
    VisitorLatex* test = new VisitorLatex();

    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* rand = new Rand();
    
    Base* div = new Div(four, two);
    EXPECT_EQ(test->PrintLaTeX(div), "${\\frac{4.000000}{2.000000}}$");
}

TEST(VisitorLatexTest, LatexVisitsPow) {
    VisitorLatex* test = new VisitorLatex();

    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* rand = new Rand();

    Base* power = new Pow(four, two);
    EXPECT_EQ(test->PrintLaTeX(power), "${({4.000000}(^){2.000000})}$");
}

TEST(VisitorLatexTest, LatexVisitsLong) {
    VisitorLatex* test = new VisitorLatex();

    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* rand = new Rand();
    Base* div = new Div(four, two);
    Base* rand_test = new Pow (four, rand);

    Base* long_eq = new Div (div, div);
    EXPECT_EQ(test->PrintLaTeX(long_eq), "${\\frac{\\frac{4.000000}{2.000000}}{\\frac{4.000000}{2.000000}}}$");
}
#endif //__TEST_HPP__
