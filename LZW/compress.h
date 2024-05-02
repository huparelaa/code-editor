#include <stdio.h>
#include <assert.h>
#include <filesystem>
#include <cstdio>
#include <stdint.h>

static inline void write_code_to_file(FILE *file, uint32_t code, size_t bytes_per_code);

int compress(const char* file_name);