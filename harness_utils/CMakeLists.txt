add_library(harness_utils INTERFACE)
target_include_directories(harness_utils INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/fuzzing_utils")

add_library(fuzzing_utils STATIC fuzzing_utils/fuzzing_utils.cc)
target_include_directories(fuzzing_utils INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/fuzzing_utils")