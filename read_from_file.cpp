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

    return (size_t)st.st_size + 1;
}

void allocate_arr_of_ptrs(text_params* str_tp)
{
    str_tp -> arr_of_ptrs_on_strs[0] = str_tp -> buff[0];

    size_t num_of_ptr = 1;
    size_t num_of_symb = 0;

    for(num_of_symb = 0; num_of_symb < str_tp -> len_buff; num_of_symb++)
    {
        if(str_tp -> buff[num_of_symb] == '\n')
        {
            str_tp -> arr_of_ptrs_on_strs[num_of_ptr] = str_tp -> buff[num_of_symb + 1];
            num_of_ptr++;
        }
    }        
}

FILE* open_file()
{
    const char* path_to_file = "Mockingbird.txt";

    FILE* open_file = fopen(path_to_file, "r");

    assert(open_file != NULL);
    assert(ferror(open_file) == 0);

    return open_file;
}

text_params read_from_file()
{
    FILE* file = open_file();

    text_params tp = constructor_text_params(0, 0, NULL, NULL);

    tp.len_buff = count_symbls(file);

    //printf("%zu\n", tp.len_buff);  

    tp.buff = (char*) calloc(tp.len_buff, sizeof(char));

    fread(tp.buff, sizeof(char), tp.len_buff, file);

    tp.quantity_strs = count_strs(tp.buff, tp.len_buff) + 1;

    //printf("%zu\n", tp.quantity_strs);   

    tp.arr_of_ptrs_on_strs = (char*) calloc(tp.quantity_strs, sizeof(char*));

    allocate_arr_of_ptrs(&tp);

    //for(size_t num_of_symb = 0; num_of_symb < tp.quantity_strs; num_of_symb++)
    //{
    //    printf("%d\n", tp.arr_of_ptrs_on_strs[num_of_symb]);
    //}      

    return tp;
}

text_params constructor_text_params(size_t len_buff, size_t quantity_strs, char* buff, char* arr_of_ptrs)
{
    text_params constructor_params = {};

    constructor_params.len_buff            = len_buff;
    constructor_params.quantity_strs       = quantity_strs;
    constructor_params.buff                = buff;
    constructor_params.arr_of_ptrs_on_strs = arr_of_ptrs;

    return constructor_params;
}

void destructor_text_params(text_params* tp)
{
    free(tp -> buff);
    free(tp -> arr_of_ptrs_on_strs);
}