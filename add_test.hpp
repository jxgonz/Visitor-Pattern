#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "visitor.hpp"
#include "add.hpp"

TEST(AddTest, AddTwoNonZeros) {
    Base* leftVal = new Op (7.0);
    Base* rightVal = new Op (7.0);
    Base* test = new Add(leftVal, rightVal);
    EXPECT_DOUBLE_EQ(test->evaluate(), 14.0);
    EXPECT_EQ(test -> stringify(), "(7.000000 + 7.000000)");
    EXPECT_EQ(test -> get_child(0), nullptr);
    EXPECT_EQ(test -> number_of_children(), 0);
}

TEST(AddTest, AddPosAndNeg) {
    Base* leftVal = new Op (-9.0);
    Base* rightVal = new Op (20.0);
    Base* test = new Add(leftVal, rightVal);
    EXPECT_DOUBLE_EQ(test->evaluate(), 11.0);
    EXPECT_EQ(test -> stringify(), "(-9.000000 + 20.000000)");
    EXPECT_EQ(test -> get_child(0), nullptr);
    EXPECT_EQ(test -> number_of_children(), 0);
}

#endif //__ADD_TEST_HPP__
