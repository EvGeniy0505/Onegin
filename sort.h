#ifndef SORT
#define SORT

#include "read_from_file.h"



void bubble_sort(text_params* text_p, int comp(const str* str_1, const str* str_2));

int my_strcmp(const str* str_1, const str* str_2);

int my_strcmp_back(const str* str_1, const str* str_2);

int QSORT_COMPARE(const void* a, const void* b);

void my_qsort(void* sort_system, size_t elements, size_t size, int COMPARE(const void* a, const void* b));

void byte_swap(void* a, void* b, size_t size);

#endif