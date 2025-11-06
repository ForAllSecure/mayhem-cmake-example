#include "fuzzing_utils/entire_file_utils.h"

typedef int (*HarnessFunction)(const char*, size_t);

#define HARNESS(...) \
static HarnessFunction harnesses[] = { \
	__VA_ARGS__ \
}; \
int main(int argc, char* args[]) { \
    ::testing::InitGoogleTest(&argc, args); \
    if (argc > 1) {                         \
        EntireFile file = read_entire_file_into_memory(args[1]); \
        if (!file.contents) { \
            fprintf(stderr, "Failed to open input file: %s\n", args[1]); \
            return 1; \
        } \
	if (file.len < 2) { \
	    return 1; \
        } \
	size_t harness_index = file.contents[0] % (sizeof(harnesses) / sizeof((harnesses)[0])); \
        return harnesses[harness_index](file.contents + 1, file.len - 1); \
    } \
    return RUN_ALL_TESTS(); \
}
