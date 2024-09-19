#include "read_from_file.h"
#include "sort.h"


int main()
{
    struct text_params tp = read_from_file();

    // qsort(tp.arr_of_ptrs, tp.quantity_strs, sizeof(char*), COMPARE); 

    // print_ptrs(&tp);

    bubble_sort_back(&tp);

    print_ptrs_back(&tp);

    bubble_sort(&tp);

    print_ptrs(&tp);

    print_arr(&tp); 

    destructor_text_params(&tp);
    
    return 0;
}