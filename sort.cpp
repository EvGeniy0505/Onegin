#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sort.h"



void bubble_sort(text_params* text_p, int comp(const str* str_1, const str* str_2))
{
    for(size_t i = text_p -> quantity_strs; i > 0; i--)
    {
        for(size_t j = 0; j < i - 1; j++)
        {
            str* str_1 = &text_p -> arr_of_ptrs[j];
            str* str_2 = &text_p -> arr_of_ptrs[j + 1];

            int compare = comp(str_1, str_2);

            if(compare > 0)
            {
                str swap = *str_1;
                *str_1 = *str_2;
                *str_2 = swap;
            }
        }

    }
}

int my_strcmp(const str* str_1, const str* str_2)
{
    const char* string_1 = str_1 -> begin; 
    const char* string_2 = str_2 -> begin;

    while((*string_1 == *string_2)  && *string_1 && *string_2)
    {
        string_1++;
        string_2++;

        if(*string_2 == '\0' && *string_1 == '\0')
        {
            return 0;
        }
    }

    return *(string_1) - *(string_2);
}

int my_strcmp_back(const str* str_1, const str* str_2)
{
    const char* string_1_b = str_1 -> begin; 
    const char* string_2_b = str_2 -> begin;
    const char* string_1_e = str_1 -> end; 
    const char* string_2_e = str_2 -> end;

    while((*string_1_e == *string_2_e) && *string_1_e && *string_2_e)
    {
        string_1_e--;
        string_2_e--;

        if(*string_2_e == *string_2_b && *string_1_e == *string_1_b)
        {
            return 0;
        }
    }

    return *str_1 -> end - *str_2 -> end;
}

// int COMPARE (const str* a, const str* b)
// {
//    const char* real_a = *(const char* const*)a;
//    const char* real_b = *(const char* const*)b;

//    return(strcmp(real_a, real_b));
// }