#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <assert.h>


size_t count_symbls(FILE* all_file);
size_t count_strs(char* text, size_t len_text);


int main()
{
    FILE* file = fopen("Mockingbird.txt", "r");

    assert(file != 0);
    assert(ferror(file) != 0);

    size_t len_buff = 15;

    printf("%zu", len_buff);  

    char* buff = (char*) calloc(len_buff, sizeof(char));

    fread(buff, sizeof(char), len_buff, file);

    size_t quantity_strs = count_strs(buff, len_buff) + 1;

    printf("%zu", quantity_strs);   // TODO спросить вопрос по флагам 

    char ** arr_of_ptrs_on_strs = (char**) calloc(quantity_strs, sizeof(char*));

    arr_of_ptrs_on_strs[0] = &buff[0];

    size_t num_of_ptr = 1;

    size_t num_of_symb = 0;

    for(num_of_symb = 0; num_of_symb < quantity_strs; num_of_symb++)
    {
        if(buff[num_of_symb] == '/n')
        {
            arr_of_ptrs_on_strs[num_of_ptr] = &buff[num_of_symb + 1];

            num_of_ptr++;
        }
    }        



    

    //fstat;

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

//size_t count_symbls(FILE* all_file)
//{
//    struct stat symb_in_buff = {};
//
//    fstat(symb_in_buff);
//}
