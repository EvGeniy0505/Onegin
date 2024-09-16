#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <assert.h>

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

void Constructor_text_params(text_params* tp_constr);


int main()
{
    const char* path_to_file = "Mockingbird.txt";

    FILE* file = fopen(path_to_file, "r");

    assert(file != NULL);
    assert(ferror(file) == 0);

    struct text_params tp = {};

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

    free(tp.buff);
    free(tp.arr_of_ptrs_on_strs);

    //void* q_sort(void* arr_of_ptrs_on_strs, size_t (tp -> quantity_strs), size_t size, int(*compare)(void* a, void* b));   

    return 0;
}


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

//void Constructor_text_params(text_params* tp_constr)
//{
//    tp_constr -> 
//}
