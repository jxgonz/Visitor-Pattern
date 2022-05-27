#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__
#include "gtest/gtest.h"
#include "div.hpp"

using namespace std;

TEST(DivTest, DivEvaluateZeroNum) {
    Base* left = new Op(0.0);
    Base* right = new Op(4.0);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), 0);
    EXPECT_EQ(test -> stringify(), "(0.000000 / 4.000000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(DivTest, DivEvaluateNegNum) {
    Base* left = new Op(-4.0);
    Base* right = new Op(2.0);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), -2);
    EXPECT_EQ(test -> stringify(), "(-4.000000 / 2.000000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);

}

TEST(DivTest, DivEvaluateNegDen) {
    Base* left = new Op(4.0);
    Base* right = new Op(-2.0);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), -2);
    EXPECT_EQ(test -> stringify(), "(4.000000 / -2.000000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(DivTest, DivEvaluateSameNumDen) {
    Base* left = new Op(4.0);
    Base* right = new Op(4.0);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), 1);
    EXPECT_EQ(test -> stringify(), "(4.000000 / 4.000000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(DivTest, DivEvaluateDecimalNum) {
    Base* left = new Op(0.5);
    Base* right = new Op(4.0);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), 0.125);
    EXPECT_EQ(test -> stringify(), "(0.500000 / 4.000000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(DivTest, DivEvaluateDecimalDen) {
    Base* left = new Op(4.0);
    Base* right = new Op(0.5);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), 8);
    EXPECT_EQ(test -> stringify(), "(4.000000 / 0.500000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(DivTest, DivEvaluateOneNum) {
    Base* left = new Op(1.0);
    Base* right = new Op(4.0);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), 0.25);
    EXPECT_EQ(test -> stringify(), "(1.000000 / 4.000000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(DivTest, DivEvaluateOneDen) {
    Base* left = new Op(4.0);
    Base* right = new Op(1.0);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), 4);
    EXPECT_EQ(test -> stringify(), "(4.000000 / 1.000000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(DivTest, DivEvaluateLargeNum) {
    Base* left = new Op(1234.0);
    Base* right = new Op(2.0);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), 617);
    EXPECT_EQ(test -> stringify(), "(1234.000000 / 2.000000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(DivTest, DivEvaluateLargeDen) {
    Base* left = new Op(10.0);
    Base* right = new Op(1000.0);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), 0.01);
    EXPECT_EQ(test -> stringify(), "(10.000000 / 1000.000000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);
}

TEST(DivTest, DivEvaluateReg) {
    Base* left = new Op(9.0);
    Base* right = new Op(3.0);
    Base* test = new Div(left, right);
    EXPECT_DOUBLE_EQ(test -> evaluate(), 3);
    EXPECT_EQ(test -> stringify(), "(9.000000 / 3.000000)");
    EXPECT_EQ(test->number_of_children(), 2);
    EXPECT_EQ(test->get_child(0), left);
    EXPECT_EQ(test->get_child(1), right);
    EXPECT_EQ(test->get_child(2), nullptr);
}

#endif
