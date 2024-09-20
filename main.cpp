#include "read_from_file.h"
#include "sort.h"


int main()
{
    struct text_params tp = constructur_text_params();

    // qsort(tp.arr_of_ptrs, tp.quantity_strs, sizeof(char*), COMPARE);

    // print_ptrs(&tp);

    bubble_sort(&tp, my_strcmp_back);

    printf("%s\n", "\x1B[4;31mBack sorted text:\x1B[0;37m\n");

    print_ptrs(&tp);

    bubble_sort(&tp, my_strcmp);

    printf("%s\n", "\x1B[4;35mSorted text:\x1B[0;37m\n");

    print_ptrs(&tp);

    print_arr(&tp);

    destructor_text_params(&tp);

    return 0;
}