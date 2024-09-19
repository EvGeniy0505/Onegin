#ifndef SORT
#define SORT

#include "read_from_file.h"



int my_strcmp(const char* str_1, const char* str_2);

void bubble_sort(text_params* text_p);

int my_strcmp_back(char* str_1_b, const char* str_2_b, char* str_1_e, const char* str_2_e);

void bubble_sort_back(text_params* text_p);

int COMPARE(const void* a, const void* b);

#endif