#include <stdio.h>

int COMPARE_INT(const void* a, const void* b);

void my_qsort(void* sort_system, size_t elements, size_t size, int COMPARE(const void* a, const void* b));

int main()
{
    int len_arr = 8;

    int arr[len_arr] = {25, 52, 7, 10, 57, 1, 39, -3};

    my_qsort(arr, len_arr, sizeof(*arr), COMPARE_INT);

    for(size_t i = 0; i < len_arr; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}

int COMPARE_INT(const void* a, const void* b)
{
    const int real_a = *(const int*)a;
    const int real_b = *(const int*)b;

    return real_a - real_b;
}

void my_qsort(void* sort_system, size_t elements, size_t size, int COMPARE(const void* a, const void* b))
{
    size_t half_symb = elements / 2;
    
    void* ptr_1 = 0;
    void* ptr_2 = 0;

    for(size_t i = 0; i < elements; i++)
    {
        if(COMPARE((int*) sort_system[i], (int*) sort_system[half_symb]))
        {
            // ptr_1++;
            // ptr_2++;

            
        }
    }
}