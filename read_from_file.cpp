#include <sys/stat.h>
#include <assert.h>

#include "read_from_file.h"

#define RESET   "\033[0m"
#define RED     "\033[1;31m"

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
    str_tp -> arr_of_ptrs_on_strs[0] = &str_tp -> buff[0];

    size_t num_of_ptr = 1;

    for(size_t num_of_symb = 0; num_of_symb < str_tp -> len_buff; num_of_symb++)
    {
        if(str_tp -> buff[num_of_symb] == '\n')
        {
            str_tp -> arr_of_ptrs_on_strs[num_of_ptr] = &str_tp -> buff[num_of_symb + 1];

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

    tp.buff = (char*) calloc(tp.len_buff, sizeof(char));

    fread(tp.buff, sizeof(char), tp.len_buff, tp.file);

    tp.quantity_strs = count_strs(tp.buff, tp.len_buff) + 1;

    //printf("%zu\n", tp.quantity_strs);   

    tp.arr_of_ptrs_on_strs = (char**) calloc(tp.quantity_strs, sizeof(char*));

    allocate_arr_of_ptrs(&tp);

   
    return tp;
}

void print_arr(text_params* tp)
{ 
    printf("\x1B[1;31;40mOriginal text:\x1B[0;30;40m\n");

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
    printf("%s\n", "\x1B[1;31;40mSorted text:\x1B[0;30;40m\n");

    for(size_t num_of_ptr = 0; num_of_ptr < tp -> quantity_strs; num_of_ptr++)
    {
        //const char* curSymb = &tp -> arr_of_ptrs_on_strs[num_of_ptr][0];

        // size_t symb = 0;

        // char print_symb = tp -> arr_of_ptrs_on_strs[num_of_ptr][symb];

        // while(print_symb != '\n' && print_symb != '\0')
        // {
        //     printf("%s", print_symb);

        //     symb++;

        //     print_symb = tp -> arr_of_ptrs_on_strs[num_of_ptr][symb];
        // }
        // putchar('\n');

        printf("%s\n", tp -> arr_of_ptrs_on_strs[num_of_ptr]);
    }     
} 

text_params constructor_text_params(FILE* name_file, size_t len_buff, size_t quantity_strs, char* buff, char** arr_of_ptrs)
{
    text_params constructor_params = {};

    constructor_params.file                = name_file;
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