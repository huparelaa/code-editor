#include <stdio.h>

void free_table(char *table[], uint32_t total_codes);
void get_current_code_size(size_t *code_size, uint32_t *nuevo, FILE *input_file, long int file_offset_24bit_codes, long int file_offset_32bit_codes);
static inline void write_contents_to_file(FILE *file, char *buffer, unsigned int size);
int decompress(const char* file_name);
