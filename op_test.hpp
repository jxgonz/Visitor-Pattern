#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include <string>

#include "gtest/gtest.h"

#include "visitor.hpp"
#include "op.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(0.0);
    EXPECT_EQ(test->evaluate(), 0.0);
    EXPECT_EQ(test->stringify(), "0.000000");
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

TEST(OpTest, OpEvaluateLargeNeg) {
    Op* test = new Op(-134.7);
    EXPECT_EQ(test->evaluate(), -134.7);
    EXPECT_EQ(test->stringify(), "-134.700000");
    EXPECT_EQ(test->number_of_children(), 0);
    EXPECT_EQ(test->get_child(0), nullptr);
}

TEST(OpTest, OpEvaluateSmallPos) {
    Op* test = new Op(0.4);
    EXPECT_EQ(test->evaluate(), 0.4);
    EXPECT_EQ(test->stringify(), "0.400000");
    EXPECT_EQ(test->number_of_children(), 0);
    EXPECT_EQ(test->get_child(0), nullptr);
}

TEST(OpTest, OpEvaluateLargePos) {
    Op* test = new Op(134.7);
    EXPECT_EQ(test->evaluate(), 134.7);
    EXPECT_EQ(test->stringify(), "134.700000");
    EXPECT_EQ(test->number_of_children(), 0);
    EXPECT_EQ(test->get_child(0), nullptr);
}

#endif //__OP_TEST_HPP__
