add_library(calculator STATIC calculator.c calculator.h)
target_include_directories(calculator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(calculator_app main.c)
target_link_libraries(calculator_app PRIVATE calculator)