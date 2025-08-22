#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <gtest/gtest.h>

#include "harness_utils.h"

extern "C" {
  #include "calculator.h"
}

int test_add(const char* buf, size_t len) {
  int x, y;
  if (len < sizeof(int) * 2) {
    return 1;
  }
  sscanf(buf, "%d %d", &x, &y);
  assert(add(x, y) == x + y);
  return 0;
}

int test_subtract(const char* buf, size_t len) {
  int x, y;
  if (len < sizeof(int) * 2) {
    return 1;
  }
  sscanf(buf, "%d %d", &x, &y);
  assert(subtract(x, y) == x - y);
  return 0;
}

int test_multiply(const char* buf, size_t len) {
  int x, y;
  if (len < sizeof(int) * 2) {
    return 1;
  }
  sscanf(buf, "%d %d", &x, &y);
  assert(multiply(x, y) == x * y);
  return 0;
}

int test_divide(const char* buf, size_t len) {
  int x, y;
  if (len < sizeof(int) * 2) {
    return 1;
  }
  sscanf(buf, "%d %d", &x, &y);
  assert(divide(x, y) == x / y);
  return 0;
}

int test_factor_game(const char* buf, size_t len) {
  int x, y;
  if (len < sizeof(int) * 2) {
    return 1;
  }
  sscanf(buf, "%d %d", &x, &y);
  factor_game(x, y); // bug is hidden in factor_game() itself, no need for extra assert() here
  return 0;
}

TEST(CalculatorTest, TestAdd) {
  char buf[64] = {1, 2};
  test_add(buf, sizeof(buf));
}

TEST(CalculatorTest, TestSubtract) {
  char buf[64] = {2, 1};
  test_subtract(buf, sizeof(buf));
}

TEST(CalculatorTest, TestMultiply) {
  char buf[64] = {3, 2};
  test_multiply(buf, sizeof(buf));
}

TEST(CalculatorTest, TestDivide) {
  char buf[64] = {6, 2};
  test_divide(buf, sizeof(buf));
}

TEST(CalculatorTest, TestFactorGame) {
  char buf[64] = {6, 2};
  test_factor_game(buf, sizeof(buf));
}

HARNESS(test_add, test_subtract, test_multiply, test_divide, test_factor_game)