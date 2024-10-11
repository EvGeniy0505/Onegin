#include "read_from_file.h"
#include "sort.h"
#include <assert.h>

int main()
{
    struct text_params tp = constructur_text_params("Mockingbird.txt");

    FILE* text = fopen("text_in_file.txt", "a");

    my_qsort(tp.arr_of_ptrs, tp.quantity_strs, sizeof(*tp.arr_of_ptrs), QSORT_COMPARE);

    color_printf(text, WHITE, "My qsort:\n");

    print_ptrs(&tp, text);

    qsort(tp.arr_of_ptrs, tp.quantity_strs, sizeof(*tp.arr_of_ptrs), QSORT_COMPARE);

    color_printf(text, GREEN, "Program qsort:\n");

    print_ptrs(&tp, text);

    fprintf(text, "\n\n\n");

    bubble_sort(&tp, my_strcmp_back);

    color_printf(text, RED, "Back sort:\n");

    print_ptrs(&tp, text);

    fprintf(text, "\n\n\n");

    bubble_sort(&tp, my_strcmp);

    color_printf(text, PURPLE, "Sort text:\n");

    print_ptrs(&tp, text);

    fprintf(text, "\n\n\n");

    print_arr(&tp, text);

    destructor_text_params(&tp);

    fclose(text);

    color_printf(stdout, PURPLE, "%d %s %i\n", 52, "polina solnishko", 57);

    return 0;
}