#include <stdio.h>
#include <stdlib.h>

struct text_params
{
    size_t len_buff;
    size_t quantity_strs;
    char* buff;
    char* arr_of_ptrs_on_strs;
};



size_t count_symbls(FILE* all_file);

size_t count_strs(char* text, size_t len_text);

void allocate_arr_of_ptrs(text_params* str_tp);

text_params read_from_file();

FILE* open_file();

text_params constructor_text_params(size_t len_buff, size_t quantity_strs, char* buff, char* arr_of_ptrs);

void destructor_text_params(text_params* tp);
