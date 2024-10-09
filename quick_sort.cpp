#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int QSORT_COMPARE (const void* a, const void* b);

void my_qsort(void* sort_system, size_t elements, size_t size, int COMPARE(const void* a, const void* b));

void byte_swap(void* a, void* b, size_t size);

int main()
{
    int len_arr = 8;

    const char* arr[len_arr] = {"femkms", "dlekwme", "fkemfdlces", "amdwmd", "wkldsm", "wkcdcss", "2,sa", "o"};

    my_qsort(arr, len_arr, sizeof(*arr), QSORT_COMPARE);

    for(size_t i = 0; i < len_arr; i++)
    {
        printf("%s\n", arr[i]);
    }

    putchar('\n');

    return 0;
}

int QSORT_COMPARE (const void* a, const void* b)
{
    return(strcmp(*(const char**)a, *(const char**)b));
}

void my_qsort(void* sort_system, size_t elements, size_t size, int COMPARE(const void* a, const void* b))
{
    void* pivot = (sort_system + size * (rand() % (elements)));

    int ptr_1 = 0;
    int ptr_2 = elements - 1;

    do
    {
        while(COMPARE((sort_system + ptr_1 * size), pivot) < 0)
        {
            ptr_1++;
        }

        while(COMPARE((sort_system + ptr_2 * size), pivot) > 0)
        {
            ptr_2--;
        }

        if(ptr_1 <= ptr_2)
        {
            byte_swap(sort_system + ptr_1 * size, sort_system + ptr_2 * size, size);

            ptr_1++;
            ptr_2--;
        }

    }while(ptr_1 <= ptr_2);

    if(ptr_2 > 0)
    {
        my_qsort(sort_system, ptr_2 + 1 , size, COMPARE);
    }
    if(ptr_1 < elements)
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