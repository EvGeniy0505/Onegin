#include "read_from_file.h"
#include "sort.h"

int main()
{
    struct text_params tp = constructur_text_params();

    // qsort(tp.arr_of_ptrs, tp.quantity_strs, sizeof(char*), COMPARE);

    // print_ptrs(&tp);

    bubble_sort(&tp, my_strcmp_back);

    color_printf(stdout, "Back sort:\n", RED);

    print_ptrs(&tp);

    bubble_sort(&tp, my_strcmp);

    color_printf(stdout, "Sort text:\n", PURPLE);

    print_ptrs(&tp);

    print_arr(&tp);

    destructor_text_params(&tp);

    return 0;
}