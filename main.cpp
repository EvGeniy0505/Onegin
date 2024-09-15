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

void count_symbls(FILE* all_file, text_params* all_symbls);
size_t count_strs(char* text, size_t len_text);


int main()
{
    FILE* file = fopen("Mockingbird.txt", "r");

    assert(file != NULL);
    assert(ferror(file) == 0);

    struct text_params* tp = NULL;

    count_symbls(file, tp);

    printf("%zu", tp -> len_buff);  

    char* buff = (char*) calloc(tp -> len_buff, sizeof(char));

    fread(buff, sizeof(char), tp -> len_buff, file);

    tp -> quantity_strs = count_strs(buff, tp -> len_buff) + 1;

    printf("%zu", tp -> quantity_strs);   

    char* arr_of_ptrs_on_strs = (char*) calloc(tp -> quantity_strs, sizeof(char*));

    arr_of_ptrs_on_strs[0] = buff[0];

    size_t num_of_ptr = 1;

    size_t num_of_symb = 0;

    for(num_of_symb = 0; num_of_symb < tp -> quantity_strs; num_of_symb++)
    {
        if(buff[num_of_symb] == '/n')
        {
            arr_of_ptrs_on_strs[num_of_ptr] = buff[num_of_symb + 1];

            num_of_ptr++;
        }
    }        

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


void count_symbls(FILE* all_file, text_params* all_symbls)
{
    struct stat st;

    fstat(fileno(all_file), &st);

    all_symbls -> len_buff = st.st_size + 1;
}
