#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sort.h"



void bubble_sort(text_params* text_p, int comp(str* str_1, str* str_2))
{
    for(size_t i = text_p -> quantity_strs - 1; i > 0; i--)
    {
        for(size_t j = 0; j < i - 1; j++)
        {
            str str_1 = text_p -> arr_of_ptrs[j];
            str str_2 = text_p -> arr_of_ptrs[j + 1];

            int compare = comp(&str_1, &str_2);

            if(compare > 0)
            {
                str swap = str_2;
                str_1 = str_2;
                str_2 = swap;
            }
        }

    }
}

int my_strcmp(str* str_1, str* str_2)
{
    while((*str_1 -> begin == *str_2 -> begin)  && *str_1 -> begin && *str_2 -> begin)
    {
        str_1->begin++;
        str_2->begin++;

        if(*str_2 -> begin == '\0' && *str_1 -> begin == '\0')
        {
            return 0;
        }
    }

    return *(str_1 -> begin) - *(str_2 -> begin);
}

int my_strcmp_back(str* str_1, str* str_2)
{
    while((*str_1->end == *str_2->end) && *str_1->end && *str_2->end)
    {
        str_1->end--;
        str_2->end--;

        if(*str_2->end == *str_2->begin && *str_1->end == *str_1->begin)
        {
            return 0;
        }
    }

    return *str_1->end - *str_2->end;
}

int COMPARE (const void* a, const void* b)
{
   const char* real_a = *(const char* const*)a;
   const char* real_b = *(const char* const*)b;

   return(strcmp(real_a, real_b));
}