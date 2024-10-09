#include "read_from_file.h"
#include "sort.h"

int main()
{
    struct text_params tp = constructur_text_params();

    color_printf(stdout, GREEN, "My qsort text:\n");

    my_qsort(tp.arr_of_ptrs, tp.quantity_strs, sizeof(*tp.arr_of_ptrs), QSORT_COMPARE);

    print_ptrs(&tp);

    color_printf(stdout, GREEN, "Program qsort text:\n");

    qsort(tp.arr_of_ptrs, tp.quantity_strs, sizeof(*tp.arr_of_ptrs), QSORT_COMPARE);

    print_ptrs(&tp);

    printf("\n\n\n");

    bubble_sort(&tp, my_strcmp_back);

    color_printf(stdout, RED, "Back sort:\n");

    print_ptrs(&tp);

    printf("\n\n\n");

    bubble_sort(&tp, my_strcmp);

    color_printf(stdout, PURPLE, "Sort text:\n");

    print_ptrs(&tp);

    printf("\n\n\n");

    print_arr(&tp);

    destructor_text_params(&tp);

    color_printf(stdout, PURPLE, "%d %s %i\n", 52, "polina solnishko", 57);

    return 0;
}