#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "mult.hpp"
#include "op.hpp"

using namespace std;

TEST(MultTest, MultTwoNonZeros) {
    Base* leftVal = new Op (7.0);
    Base* rightVal = new Op (9.0);
    Base* test = new Mult(leftVal, rightVal);
    EXPECT_DOUBLE_EQ(test->evaluate(), 63.0);
    EXPECT_EQ(test->stringify(), "(7.000000 * 9.000000)"); 
    EXPECT_EQ(test -> get_child(0), leftVal);
    EXPECT_EQ(test-> get_child(1), rightVal);
    EXPECT_EQ(test-> get_child(2), nullptr);
    EXPECT_EQ(test -> number_of_children(), 2);
}

TEST(MultTest, MultPosAndNeg) {
    Base* leftVal = new Op (-7.0);
    Base* rightVal = new Op (15.0);
    Base* test = new Mult(leftVal, rightVal);
    EXPECT_DOUBLE_EQ(test->evaluate(), -105.0);
    EXPECT_EQ(test->stringify(), "(-7.000000 * 15.000000)");
    EXPECT_EQ(test -> get_child(0), leftVal);
    EXPECT_EQ(test-> get_child(1), rightVal);
    EXPECT_EQ(test-> get_child(2), nullptr);
    EXPECT_EQ(test -> number_of_children(), 2);
}

TEST(MultTest, MultZeroAndNonZero) {
    Base* leftVal = new Op (13.0);
    Base* rightVal = new Op (0.0);
    Base* test = new Mult(leftVal, rightVal);
    EXPECT_DOUBLE_EQ(test->evaluate(), 0.0);
    EXPECT_EQ(test->stringify(), "(13.000000 * 0.000000)");
    EXPECT_EQ(test -> get_child(0), leftVal);
    EXPECT_EQ(test-> get_child(1), rightVal);
    EXPECT_EQ(test-> get_child(2), nullptr);
    EXPECT_EQ(test -> number_of_children(), 2);
}

TEST(MultTest, MultTwoNeg) { 
    Base* leftVal = new Op (-4.0);
    Base* rightVal = new Op (-5.0);
    Base* test = new Mult(leftVal, rightVal);
    EXPECT_DOUBLE_EQ(test->evaluate(), 20.0);
    EXPECT_EQ(test->stringify(), "(-4.000000 * -5.000000)");
    EXPECT_EQ(test -> get_child(0), leftVal);
    EXPECT_EQ(test-> get_child(1), rightVal);
    EXPECT_EQ(test-> get_child(2), nullptr);
    EXPECT_EQ(test -> number_of_children(), 2);
}

#endif // __MULT_TEST_HPP__
