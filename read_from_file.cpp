#include <sys/stat.h>
#include <assert.h>
#include <stdarg.h>

#include "read_from_file.h"

size_t count_strs(char* text, size_t len_text)
{

    assert (text);
    size_t quantity_strs = 0;

    for(size_t i = 0; i < len_text; i++)
    {
        if(text[i] == '\n')
        {
            quantity_strs++;
        }
        // if(text[i + 1] == '\n') // TODO: убрать нахуй все пустые строки
        // {
        //     quantity_strs--;
        // }
    }

    quantity_strs++;

    return quantity_strs;
}

// size_t value_plus_plus(size_t* value); // === a++
// size_t plus_plus_value(size_t* value); // === ++a

size_t count_symbls(FILE* all_file)
{
    assert(all_file);

    struct stat st;

    fstat(fileno(all_file), &st);

    return (size_t)st.st_size;
}

void split_lines(text_params* tp)
{
    assert(tp);

    tp -> arr_of_ptrs[0].begin = &tp -> buff[0];

    size_t num_of_ptr = 1;

    for(size_t num_of_symb = 0; num_of_symb < tp -> len_buff; num_of_symb++)
    {
        if(tp -> buff[num_of_symb] == '\n')
        {
            tp -> arr_of_ptrs[num_of_ptr].begin   = &tp -> buff[num_of_symb + 1];
            tp -> arr_of_ptrs[num_of_ptr - 1].end = &tp -> buff[num_of_symb - 1];

            tp -> buff[num_of_symb] = '\0';

            num_of_ptr++;
        }

    }
}

FILE* open_file(text_params* tp)
{
    assert(tp);

    const char* path_to_file = "Mockingbird.txt";

    tp -> file = fopen(path_to_file, "r");

    assert(tp -> file);
    assert(ferror(tp -> file) == 0); // красава!

    return tp -> file;
}

text_params constructur_text_params()
{
    text_params tp = {};

    open_file(&tp);

    tp.len_buff = count_symbls(tp.file);

    // printf("%zu\n", tp.len_buff);

    tp.buff = (char*) calloc(tp.len_buff + 1, sizeof(char));

    fread(tp.buff, sizeof(char), tp.len_buff, tp.file);

    tp.quantity_strs = count_strs(tp.buff, tp.len_buff); 

    //printf("%zu\n", tp.quantity_strs);

    tp.arr_of_ptrs = (str*) calloc(tp.quantity_strs, sizeof(str));

    assert(tp.arr_of_ptrs != NULL);

    split_lines(&tp);

    return tp;
}

void color_printf(FILE* stream, const char* text, int color)
{
    fprintf(stream, "\x1B[4;%dm%s\x1B[0;%dm", color, text, WHITE);
}

void print_arr(text_params* tp)
{
    // va_arg list: vprintf();
    color_printf(stdout, "Original text:\n", YELLOW);

    int count_1 = 0;
    int count_2 = 0; 

    for(size_t num_of_symb = 0; num_of_symb < tp -> quantity_strs; num_of_symb++)
    {
        fprintf(stdout, "%s%n\n", &tp -> buff[count_1], &count_2);

        count_1 = count_1 + count_2 + 1;
    }
}

void print_ptrs(text_params* tp)
{
    for(size_t num_of_ptr = 0; num_of_ptr < tp -> quantity_strs; num_of_ptr++)
    {
        printf("%s\n", tp -> arr_of_ptrs[num_of_ptr].begin);
    }
}

void destructor_text_params(text_params* tp)
{
    free(tp -> buff);
    free(tp -> arr_of_ptrs);
}