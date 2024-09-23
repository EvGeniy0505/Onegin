#ifndef READ_FROM_FILE
#define READ_FROM_FILE

#include <stdio.h>
#include <stdlib.h>

enum text_colors
{
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    LIGHT_BLUE,
    WHITE
};

struct str
{
    char* begin;
    char* end;
};

struct text_params
{
    FILE* file;
    size_t len_buff;
    size_t quantity_strs;
    char* buff;
    str* arr_of_ptrs;
};

size_t count_symbls(FILE* all_file);

size_t count_strs(char* text, size_t len_text);

void split_lines(text_params* str_tp);

text_params constructur_text_params();

FILE* open_file(text_params* tp);

void color_printf(FILE* stream, int color, const char* format, ...);

void print_arr(text_params* tp);

void print_ptrs(text_params* tp);

void destructor_text_params(text_params* tp);

#endif
