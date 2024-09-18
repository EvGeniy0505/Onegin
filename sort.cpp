#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sort.h"



//int strcmp_by_me(const char* str_1, const char* str_2)
//{
//    for(size_t i = 0; i < )
//}

void bubble_sort(text_params* text_p)
{
    char* swap = {};
    int compare = 0;

    for(size_t i = text_p -> quantity_strs - 1; i > 0; i--)   // TODO: тут вопрос
    {
        for(size_t j = 0; j < i; j++)
        {
            compare = strcmp((text_p -> arr_of_ptrs.begin[j]),
                             (text_p -> arr_of_ptrs.end[j + 1]));

            if(compare > 0)
            {
                swap = text_p -> arr_of_ptrs.begin[j];
                text_p -> arr_of_ptrs.begin[j] = text_p -> arr_of_ptrs.begin[j + 1];
                text_p -> arr_of_ptrs.begin[j + 1] = swap;
            }
        }

    }
}


 


int COMPARE (const void* a, const void* b)
{
   const char* real_a = *(const char**)a;
   const char* real_b = *(const char**)b;

   return(strcmp(real_a, real_b));
} 