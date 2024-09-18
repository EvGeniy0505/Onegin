#include "read_from_file.h"
#include "sort.h"


int main()
{
    struct text_params tp = read_from_file();

    qsort(tp.arr_of_ptrs.begin, tp.quantity_strs, sizeof(char*), COMPARE); 

    //bubble_sort(&tp);

    print_ptrs(&tp);

    printf("\n\n\n\n\n");

    print_arr(&tp); 

    destructor_text_params(&tp);
    
    return 0;
}