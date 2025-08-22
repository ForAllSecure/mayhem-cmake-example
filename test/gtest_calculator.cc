#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtest/gtest.h>

extern "C" {
  #include "calculator.h"
}

TEST(CalculatorTest, TestAdd) {
  EXPECT_EQ(add(1, 2), 3);
}

TEST(CalculatorTest, TestSubtract) {
  EXPECT_EQ(subtract(2, 1), 1);
}

TEST(CalculatorTest, TestMultiply) {
  EXPECT_EQ(multiply(3, 2), 6);
}

TEST(CalculatorTest, TestDivide) {
  EXPECT_EQ(divide(6, 2), 3);
}

TEST(CalculatorTest, TestFactorGame) {
  EXPECT_EQ(factor_game(6, 2), 0);
}