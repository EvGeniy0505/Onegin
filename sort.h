#ifndef SORT
#define SORT

#include "read_from_file.h"



int my_strcmp(str* str_1, str* str_2);

void bubble_sort(text_params* text_p, int comp(str* str_1, str* str_2));

int my_strcmp_back(str* str_1, str* str_2);

int COMPARE(const void* a, const void* b);

#endif