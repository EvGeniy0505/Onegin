#include <sys/stat.h>
#include <assert.h>

#include "read_from_file.h"


size_t count_strs(char* text, size_t len_text)
{
    size_t quantity_strs = 0;

    for(size_t i = 0; i < len_text; i++)
    {
        if(text[i] == '\n')
        {
            quantity_strs++;
        }
    }

    return quantity_strs;
}

size_t count_symbls(FILE* all_file)
{
    struct stat st;

    fstat(fileno(all_file), &st);

    return (size_t)st.st_size;
}

void allocate_arr_of_ptrs(text_params* str_tp)
{
    str_tp -> arr_of_ptrs[0].begin = &str_tp -> buff[0];

    size_t num_of_ptr = 1;

    for(size_t num_of_symb = 0; num_of_symb < str_tp -> len_buff; num_of_symb++)
    {
        if(str_tp -> buff[num_of_symb] == '\n')
        {
            str_tp -> arr_of_ptrs[num_of_ptr].begin   = &str_tp -> buff[num_of_symb + 1];
            str_tp -> arr_of_ptrs[num_of_ptr - 1].end = &str_tp -> buff[num_of_symb - 1];

            str_tp -> buff[num_of_symb] = '\0';

            num_of_ptr++;
        }

    }        
}

FILE* open_file(text_params* tp)
{
    const char* path_to_file = "Mockingbird.txt";

    tp -> file = fopen(path_to_file, "r");

    assert(tp -> file != NULL);
    assert(ferror(tp -> file) == 0);

    return tp -> file;
}

text_params read_from_file()
{
    text_params tp = {};

    open_file(&tp);

    tp.len_buff = count_symbls(tp.file);

    //printf("%zu\n", tp.len_buff);  

    tp.buff = (char*) calloc(tp.len_buff + 1, sizeof(char));

    fread(tp.buff, sizeof(char), tp.len_buff, tp.file);

    tp.quantity_strs = count_strs(tp.buff, tp.len_buff) + 1;

    //printf("%zu\n", tp.quantity_strs);   

    tp.arr_of_ptrs = (str*) calloc(tp.quantity_strs, sizeof(str));

    assert(tp.arr_of_ptrs != NULL);

    allocate_arr_of_ptrs(&tp);

    return tp;
}

void print_arr(text_params* tp)
{ 
    printf("\x1B[4;33mOriginal text:\x1B[0;37m\n");

    for(size_t num_of_symb = 0; num_of_symb < tp -> len_buff; num_of_symb++)
    {
        //fprintf(stdout, "%c", tp -> buff[num_of_symb]);

        if(tp -> buff[num_of_symb] == '\0')
        {
            putchar('\n');
        }
        else
        {
            putchar(tp -> buff[num_of_symb]);
        }
    }     
} 

void print_ptrs(text_params* tp)
{ 
    printf("%s\n", "\x1B[4;35mSorted text:\x1B[0;37m\n");

    for(size_t num_of_ptr = 0; num_of_ptr < tp -> quantity_strs; num_of_ptr++)
    {
        printf("%s\n", tp -> arr_of_ptrs[num_of_ptr].begin);
    }     
} 

void print_ptrs_back(text_params* tp)
{ 
    printf("%s\n", "\x1B[4;31mBack sorted text:\x1B[0;37m\n");

    for(size_t num_of_ptr = 0; num_of_ptr < tp -> quantity_strs; num_of_ptr++)
    {
        printf("%s\n", tp -> arr_of_ptrs[num_of_ptr].begin);
    }     
} 

text_params constructor_text_params(FILE* name_file, size_t len_buff, size_t quantity_strs, 
                                    char* buff,  char* arr_begining_str, char* arr_end_str)
{
    text_params constructor_params = {};

    constructor_params.file               = name_file;
    constructor_params.len_buff           = len_buff;
    constructor_params.quantity_strs      = quantity_strs;
    constructor_params.buff               = buff;
    constructor_params.arr_of_ptrs->begin = arr_begining_str;
    constructor_params.arr_of_ptrs->end   = arr_end_str;

    return constructor_params;
}

void destructor_text_params(text_params* tp)
{
    free(tp -> buff);
    free(tp -> arr_of_ptrs);
}