#include <stdio.h>

int COMPARE_INT(const int* a, const int* b);

void my_qsort(int* sort_system, size_t elements, size_t size, int COMPARE(const int* a, const int* b));

int main()
{
    int len_arr = 8;

    int arr[len_arr] = {25, 52, 7, 10, 57, 1, 39, -3};

    my_qsort(arr, len_arr, sizeof(*arr), COMPARE_INT);

    for(size_t i = 0; i < len_arr; i++)
    {
        printf("%d ", arr[i]);
    }

    putchar('\n');

    return 0;
}

int COMPARE_INT(const int* a, const int* b)
{
    const int real_a = *(const int*)a;
    const int real_b = *(const int*)b;

    return real_a - real_b;
}

void my_qsort(int* sort_system, size_t elements, size_t size, int COMPARE(const int* a, const int* b))
{
    size_t half_symb = elements / 2;
    
    int ptr_1 = 0;
    int ptr_2 = elements - 1;

    do
    {
        while(COMPARE(&sort_system[ptr_1], &sort_system[half_symb]) < 0)
        {
            ptr_1++;
        }
        while(COMPARE(&sort_system[ptr_2], &sort_system[half_symb]) > 0)
        {
            ptr_2--;
        }

        printf("%d %d\n", ptr_1, ptr_2);

        if(ptr_1 <= ptr_2)
        {
            int swap = sort_system[ptr_1];
            sort_system[ptr_1] = sort_system[ptr_2];
            sort_system[ptr_2] = swap;

            ptr_1++;
            ptr_2--;
        }


    }while(ptr_1 <= ptr_2);

    for(size_t i = 0; i < elements; i++)
    {
        printf("%d ", sort_system[i]);
    }
    putchar('\n');
    printf("%d %d\n", ptr_1, ptr_2);

    if(ptr_2 > 0)
    {
        my_qsort(sort_system, ptr_2 + 1 , sizeof(*sort_system), COMPARE_INT);
    }
    if(ptr_1 < elements - 1)
    {
        my_qsort(&sort_system[ptr_1], elements - ptr_1, sizeof(*sort_system), COMPARE_INT);
    }
}