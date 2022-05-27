#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include <string>

#include "gtest/gtest.h"

#include "visitor.hpp"
#include "op.hpp"
#include "add.hpp"

TEST(OpTest, OpNonZero) {
    Op* test = new Op(10.0);
    EXPECT_EQ(test->evaluate(), 10.0);
    EXPECT_EQ(test->stringify(), "10.000000");
    EXPECT_EQ(test->number_of_children(), 0);
    EXPECT_EQ(test->get_child(0), nullptr);
}

TEST(OpTest, OpEvaluateSmallNeg) {
    Op* test = new Op(-0.4);
    EXPECT_EQ(test->evaluate(), -0.4);
    EXPECT_EQ(test->stringify(), "-0.400000");
    EXPECT_EQ(test->number_of_children(), 0);
    EXPECT_EQ(test->get_child(0), nullptr);
}

TEST(OpTest, OpZero) {
    Op* test = new Op(0.0);
    EXPECT_EQ(test->evaluate(), 0.0);
    EXPECT_EQ(test->stringify(), "0.000000");
    EXPECT_EQ(test->number_of_children(), 0);
    EXPECT_EQ(test->get_child(0), nullptr);
}


TEST(OpTest, OpLargeNegative) {
    Op* test = new Op(-99.9);
    EXPECT_EQ(test->evaluate(), -99.9);
    EXPECT_EQ(test->stringify(), "-99.900000");
    EXPECT_EQ(test->number_of_children(), 0);
    EXPECT_EQ(test->get_child(0), nullptr);
}

TEST(OpTest, OpLargPositive) {
    Op* test = new Op(99.9);
    EXPECT_EQ(test->evaluate(), 99.9);
    EXPECT_EQ(test->stringify(), "99.900000");
    EXPECT_EQ(test->number_of_children(), 0);
    EXPECT_EQ(test->get_child(0), nullptr);
}

#endif //__OP_TEST_HPP__ 

