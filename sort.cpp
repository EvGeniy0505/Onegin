#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sort.h"



int my_strcmp(const char* str_1, const char* str_2)
{
    while((*str_1 == *str_2)  && *str_1 && *str_2)
    {
        str_1++;
        str_2++;

        if(*str_2 == '\0' && *str_1 == '\0')
        {
            return 0;
        }
    }

    return *str_1 - *str_2;
}

void bubble_sort(text_params* text_p)
{
    for(size_t i = 0; i < text_p -> quantity_strs; i++)
    {
        for(size_t j = 0; j < text_p -> quantity_strs - i - 1; j++)
        {
            int compare = my_strcmp((text_p -> arr_of_ptrs[j].begin),
                                    (text_p -> arr_of_ptrs[j + 1].begin));

            if(compare > 0)
            {
                char* swap = text_p -> arr_of_ptrs[j].begin;
                text_p -> arr_of_ptrs[j].begin = text_p -> arr_of_ptrs[j + 1].begin;
                text_p -> arr_of_ptrs[j + 1].begin = swap;
            }
        }

    }
}

int my_strcmp_back(char* str_1_b, const char* str_2_b, char* str_1_e, const char* str_2_e)
{
    while((*str_1_e == *str_2_e) && *str_1_e && *str_2_e)
    {
        str_1_e--;
        str_2_e--;

        if(*str_2_e == *str_2_b && *str_1_e == *str_1_b)
        {
            return 0;
        }
    }

    return *str_1_e - *str_2_e;
}

// TODO удали, bubble_sort должен и так уметь в любой компаратор
void bubble_sort_back(text_params* text_p)
{
    for(size_t i = text_p -> quantity_strs - 1; i > 0; i--)
    {
        for(size_t j = 0; j < i - 1; j++)
        {
            int compare = my_strcmp_back((text_p -> arr_of_ptrs[j].begin),
                                         (text_p -> arr_of_ptrs[j + 1].begin),
                                         (text_p -> arr_of_ptrs[j].end),
                                         (text_p -> arr_of_ptrs[j + 1].end));

            if(compare > 0)
            {
                str swap = text_p -> arr_of_ptrs[j];
                text_p -> arr_of_ptrs[j] = text_p -> arr_of_ptrs[j + 1];
                text_p -> arr_of_ptrs[j + 1] = swap;
            }
        }

    }
}

int COMPARE (const void* a, const void* b)
{
   const char* real_a = *(const char* const*)a;
   const char* real_b = *(const char* const*)b;

   return(strcmp(real_a, real_b));
}