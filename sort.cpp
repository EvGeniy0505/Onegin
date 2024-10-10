#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sort.h"

typedef int QCOMPARE(const void* a, const void* b);

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

int QSORT_COMPARE (const void* a, const void* b)
{
   return(my_strcmp((const str*)a, (const str*)b));
}

void my_qsort(void* sort_system, size_t elements, size_t size, int COMPARE(const void* a, const void* b))
{
    if(elements < 1)
        return;

    void* pivot_candidate = (sort_system + size * (rand() % (elements)));

    byte_swap(pivot_candidate, sort_system, size);

    void* pivot = sort_system;

    size_t ptr_1 = 1;
    size_t ptr_2 = elements - 1;

    do
    {
        while(ptr_1 < ptr_2 && COMPARE((sort_system + ptr_1 * size), sort_system) < 0)
        {
            ptr_1++;
        }

        while(ptr_2 > ptr_1 && COMPARE((sort_system + ptr_2 * size), sort_system) > 0)
        {
            ptr_2--;
        }

        if(ptr_1 < ptr_2)
        {
            byte_swap(sort_system + ptr_1 * size, sort_system + ptr_2 * size, size);

            ptr_1++;
        }

    } while(ptr_1 < ptr_2);


    if(COMPARE((sort_system + ptr_1 * size), pivot) > 0)
    {
        byte_swap(sort_system + ptr_1 * size - size, pivot, size);
    }
    else
    {
        byte_swap(sort_system + ptr_1 * size, pivot, size);
    }

    if(ptr_2 > 0)
    {
        my_qsort(sort_system, ptr_2 , size, COMPARE);
    }
    if(ptr_1 < elements - 1)
    {
        my_qsort(sort_system + ptr_1 * size, elements - ptr_1, size, COMPARE);
    }
}

void byte_swap(void* a, void* b, size_t size)
{
    char* a_real = (char*) a;
    char* b_real = (char*) b;

    for(int i = 0; i < size; i++)
    {
        char symb = a_real[i];
        a_real[i] = b_real[i];
        b_real[i] = symb;
    }
}