#ifndef __LATEX_TEST_HPP__
#define __LATEX_TEST_HPP__

#include "gtest/gtest.h"
#include "visitor.hpp"
#include "visitor_latex.hpp"
#include "iterator.hpp"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"

TEST(VisitorLatexTest, LatexVisitsAdd) {
     VisitorLatex* test = new VisitorLatex();
     Base* left = new Op(5);  
     Base* right = new Op(10);
     Base* add = new Add(left, right);
     EXPECT_EQ(test->PrintLaTex(add), "{{5.000000} + {10.000000}}";
}

TEST(VisitorLatexTest, LatexVisitsAdd) {
     VisitorLatex* test = new VisitorLatex();
     Base* left = new Op(5);
     Base* right = new Op(10);
     Base* sub = new Sub(left, right);
     EXPECT_EQ(test->PrintLaTex(sub), "{{5.000000} - {10.000000}}";
}
 
TEST(VisitorLatexTest, LatexVisitsAdd) {
     VisitorLatex* test = new VisitorLatex();
     Base* left = new Op(5);
     Base* right = new Op(10);
     Base* mult = new Mult(left, right);
     EXPECT_EQ(test->PrintLaTex(mult), "{{5.000000} * {10.000000}}";
}    

#endif //__LATEX_TEST_HPP__
