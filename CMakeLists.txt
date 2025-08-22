cmake_minimum_required(VERSION 3.15)
project(mayhem_cmake_example VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(BUILD_TESTS "Build tests" OFF)
option(BUILD_FUZZ "Build fuzzers" OFF)

add_subdirectory(main)

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory(harness_utils)
  add_subdirectory(test)
endif()

if(BUILD_FUZZ)
  if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(FATAL_ERROR "Clang is required for libFuzzer!")
  endif()
  add_subdirectory(fuzz)
endif()

