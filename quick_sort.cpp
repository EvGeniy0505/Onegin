#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int QSORT_COMPARE (const void* a, const void* b);

int IntCompare(const void* a, const void* b);

void my_qsort(void* sort_system, size_t elements, size_t size, int COMPARE(const void* a, const void* b));

void byte_swap(void* a, void* b, size_t size);

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 100000; i++)
    {
        int len_arr = 8;
        int arr[len_arr] = {2, 12, 3, 32, 35, -4, 1, 2};

        my_qsort(arr, len_arr, sizeof(*arr), IntCompare);

        bool bad = false;
        for (int i = 0; i < len_arr - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                bad = true;
                break;
            }
        }
        if (bad)
        {
            printf("BAD SORT!!!!\n");
            for(size_t i = 0; i < len_arr; i++)
            {
                printf("%d\n", arr[i]);
            }
            printf("\n");
        }
        bad = false;
    }



    putchar('\n');

    return 0;
}

int IntCompare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int QSORT_COMPARE (const void* a, const void* b)
{
    return(strcmp(*(const char**)a, *(const char**)b));
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