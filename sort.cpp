#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sort.h"



void bubble_sort(text_params* text_p)
{
    char* swap = {};
    int compare = 0;

    for(size_t i = text_p -> quantity_strs - 1; i > 0; i--)   // TODO: тут вопрос
    {
        for(size_t j = 0; j < i; j++)
        {
            compare = strcmp((text_p -> arr_of_ptrs_on_strs[j]), (text_p -> arr_of_ptrs_on_strs[j + 1]));

            if(compare > 0)
            {
                swap = text_p -> arr_of_ptrs_on_strs[j];
                text_p -> arr_of_ptrs_on_strs[j] = text_p -> arr_of_ptrs_on_strs[j + 1];
                text_p -> arr_of_ptrs_on_strs[j + 1] = swap;
            }
        }

    }
}


//int (*COMPARE) (void* a, void* b)
//{
//    const char* real_a = *(const char**)a;
//    const char* real_b = *(const char**)b;
//} 