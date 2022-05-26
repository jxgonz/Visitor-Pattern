#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "sub.hpp"
#include "op.hpp"

using namespace std;

TEST(SubTest, SubTwoNonZeros) {
    Base* leftVal = new Op (10.0);
    Base* rightVal = new Op (6.0);
    Base* test = new Sub(leftVal, rightVal);
    EXPECT_DOUBLE_EQ(test->evaluate(), 4.0);
    EXPECT_EQ(test->stringify(), "(10.000000 - 6.000000)");
    EXPECT_EQ(test -> get_child(0), leftVal);
    EXPECT_EQ(test-> get_child(1), rightVal);
    EXPECT_EQ(test-> get_child(2), nullptr);
    EXPECT_EQ(test -> number_of_children(), 2);
}


TEST(SubTest, SubPosAndNeg) {
    Base* leftVal = new Op (-10.0);
    Base* rightVal = new Op (15.0);
    Base* test = new Sub(leftVal, rightVal);
    EXPECT_EQ(test->evaluate(), -25.0);
    EXPECT_EQ(test->stringify(), "(-10.000000 - 15.000000)");
    EXPECT_EQ(test -> get_child(0), leftVal);
    EXPECT_EQ(test-> get_child(1), rightVal);
    EXPECT_EQ(test-> get_child(2), nullptr);
    EXPECT_EQ(test -> number_of_children(), 2);
}

TEST(SubTest, SubZeroAndNonZero) {
    Base* leftVal = new Op (15.0);
    Base* rightVal = new Op (0.0);
    Base* test = new Sub(leftVal, rightVal);
    EXPECT_DOUBLE_EQ(test->evaluate(), 15.0);
    EXPECT_EQ(test->stringify(), ("(15.000000 - 0.000000)"));
    EXPECT_EQ(test -> get_child(0), leftVal);
    EXPECT_EQ(test-> get_child(1), rightVal);
    EXPECT_EQ(test-> get_child(2), nullptr);
    EXPECT_EQ(test -> number_of_children(), 2);
}

#endif //__SUB_TEST_HPP__
