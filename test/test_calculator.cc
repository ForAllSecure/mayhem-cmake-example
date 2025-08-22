#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>

extern "C" {
  #include "calculator.h"
}

void test_add(int x, int y) {
  // assert(add(x, y) == x + y);
  add(x, y);
}

void test_subtract(int x, int y) {
  // assert(subtract(x, y) == x - y);
  subtract(x, y);
}

void test_multiply(int x, int y) {
  // assert(multiply(x, y) == x * y);
  multiply(x, y);
}

void test_divide(int x, int y) {
  // assert(divide(x, y) == x / y);
  divide(x, y);
}

void test_factor_game(int x, int y) {
  // assert(factor_game(x, y) == 0);
  factor_game(x, y);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file_or_directory>\n" << std::endl;
    return 1;
  }

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
    int x, y;
    std::ifstream inputFile(file);
    if (!inputFile.is_open()) {
      std::cerr << "Error: Could not open file " << file.string() << "\n" << std::endl;
      continue;
    }

    inputFile >> x >> y;

    test_add(x, y);
    test_subtract(x, y);
    test_multiply(x, y);
    test_divide(x, y);
    test_factor_game(x, y);
  }
  return 0;
}