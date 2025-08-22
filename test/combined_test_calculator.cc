#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <gtest/gtest.h>

extern "C" {
  #include "calculator.h"
}

void test_add(int x, int y) {
  EXPECT_TRUE(add(x, y) == x + y);
}

void test_subtract(int x, int y) {
  EXPECT_TRUE(subtract(x, y) == x - y);
}

void test_multiply(int x, int y) {
  EXPECT_TRUE(multiply(x, y) == x * y);
}

void test_divide(int x, int y) {
  EXPECT_TRUE(divide(x, y) == x / y);
}

void test_factor_game(int x, int y) {
  factor_game(x, y); // bug is hidden in factor_game() itself, no need for extra assert() here
}

TEST(CalculatorTest, TestAdd) {
  test_add(1, 2);
}

TEST(CalculatorTest, TestSubtract) {
  test_subtract(2, 1);
}

TEST(CalculatorTest, TestMultiply) {
  test_multiply(3, 2);
}

TEST(CalculatorTest, TestDivide) {
  test_divide(6, 2);
}

TEST(CalculatorTest, TestFactorGame) {
  test_factor_game(6, 2);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  // Check for file/directory input
  if (argc > 1) {
    std::filesystem::path input_path(argv[1]);
    if (!std::filesystem::exists(input_path)) {
      std::cerr << "Error: " << argv[1] << " does not exist.\n" << std::endl;
      return 1;
    }

    std::vector<std::filesystem::path> files;
    if (std::filesystem::is_directory(input_path)) {
      for (const auto &entry : std::filesystem::directory_iterator(input_path)) {
        if (entry.is_regular_file()) {
          files.push_back(entry.path());
        }
      }
    } else if (std::filesystem::is_regular_file(input_path)) {
      files.push_back(input_path);
    }

    for (const auto &file : files) {
      int a, b;
      std::ifstream inputFile(file);
      if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << file.string() << "\n" << std::endl;
        continue;
      }

      // Assume the input file contains our two variables
      inputFile >> a >> b;

      test_add(a, b);
      test_subtract(a, b);
      test_multiply(a, b);
      test_divide(a, b);
      test_factor_game(a, b);

      // Skip running the default tests since we're using file input
      return 0;
    }
  }

  // If no file input is provided, run standard test fixtures
  return RUN_ALL_TESTS();
}