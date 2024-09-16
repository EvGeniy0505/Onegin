#include <stdlib.h>

#include "sort.h"



void bubble_sort(text_params* text_p)
{
    for(size_t i = 0; i < text_p -> quantity_strs; i++)
    {
        for(size_t j = 0; j < text_p -> len_buff; j++)
        {
            if(text_p -> buff[j + 1] == '\n')
            {
                break;
            }

            if((text_p -> buff[j] > text_p -> buff[j + 1]))
            {
                char arg = text_p -> arr_of_ptrs_on_strs[i];
                text_p -> arr_of_ptrs_on_strs[i] = text_p -> arr_of_ptrs_on_strs[i + 1];
                text_p -> arr_of_ptrs_on_strs[i + 1] = arg;
            }
        }
    }
}