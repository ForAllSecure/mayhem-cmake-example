#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtest/gtest.h>

#include "fuzzing_utils.h"

extern "C" {
  #include "calculator.h"
}

void test_add(int x, int y) {
  EXPECT_EQ(add(x, y), x + y);
}

void test_subtract(int x, int y) {
  EXPECT_EQ(subtract(x, y), x - y);
}

void test_multiply(int x, int y) {
  EXPECT_EQ(multiply(x, y), x * y);
}

void test_divide(int x, int y) {
  EXPECT_EQ(divide(x, y), x / y);
}

void test_factor_game(int x, int y) {
  factor_game(x, y); // bug is hidden in factor_game() itself, no need for extra assert() here
}

TEST(CalculatorTest, TestAdd) {
  test_add(1, 2);
}

FUZZ_TEST(CalculatorTest, FuzzTestAdd) {
    INIT_FUZZ_TEST;
    int x = provider.ConsumeIntegral<int>();
    int y = provider.ConsumeIntegral<int>();
    test_add(x, y);
}

TEST(CalculatorTest, TestSubtract) {
  test_subtract(2, 1);
}

FUZZ_TEST(CalculatorTest, FuzzTestSubtract) {
    INIT_FUZZ_TEST;
    int x = provider.ConsumeIntegral<int>();
    int y = provider.ConsumeIntegral<int>();
    test_subtract(x, y);
}

TEST(CalculatorTest, TestMultiply) {
  test_multiply(3, 2);
}

FUZZ_TEST(CalculatorTest, FuzzTestMultiply) {
    INIT_FUZZ_TEST;
    int x = provider.ConsumeIntegral<int>();
    int y = provider.ConsumeIntegral<int>();
    test_multiply(x, y);
}

TEST(CalculatorTest, TestDivide) {
  test_divide(6, 2);
}

FUZZ_TEST(CalculatorTest, FuzzTestDivide) {
    INIT_FUZZ_TEST;
    int x = provider.ConsumeIntegral<int>();
    int y = provider.ConsumeIntegral<int>();
    if (y == 0) {
        return;
    }
    test_divide(x, y);
}

TEST(CalculatorTest, TestFactorGame) {
  test_factor_game(6, 2);
}

FUZZ_TEST(CalculatorTest, FuzzTestFactorGame) {
    INIT_FUZZ_TEST;
    int x = provider.ConsumeIntegral<int>();
    int y = provider.ConsumeIntegral<int>();
    test_factor_game(x, y);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    if (argc > 1) {
        RunFuzzTests(argv[1]);
        return 0;
    }

    return RUN_ALL_TESTS(); 
}