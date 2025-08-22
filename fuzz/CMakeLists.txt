add_executable(fuzz_calculator fuzz_calculator.cc)
target_link_libraries(fuzz_calculator PRIVATE calculator)

target_compile_options(fuzz_calculator PUBLIC -fsanitize=fuzzer)
target_link_options(fuzz_calculator PUBLIC -fsanitize=fuzzer)