#include <sys/stat.h>
#include <assert.h>

#include "read_from_file.h"

size_t count_strs(char* text, size_t len_text)
{
    size_t quantity_strs = 0;

    for(size_t i = 0; i < len_text; i++)
    {
        if(text[i] == '\n')
        {
            quantity_strs++;
        }
    }

    quantity_strs++;

    return quantity_strs;
}

// size_t value_plus_plus(size_t* value); // === a++
// size_t plus_plus_value(size_t* value); // === ++a

size_t count_symbls(FILE* all_file)
{
    struct stat st;

    fstat(fileno(all_file), &st);

    return (size_t)st.st_size;
}

void split_lines(text_params* str_tp)
{
    str_tp -> arr_of_ptrs[0].begin = &str_tp -> buff[0];

    size_t num_of_ptr = 1;

    for(size_t num_of_symb = 0; num_of_symb < str_tp -> len_buff; num_of_symb++)
    {
        if(str_tp -> buff[num_of_symb] == '\n')
        {
            str_tp -> arr_of_ptrs[num_of_ptr].begin   = &str_tp -> buff[num_of_symb + 1];
            str_tp -> arr_of_ptrs[num_of_ptr - 1].end = &str_tp -> buff[num_of_symb - 1];

            str_tp -> buff[num_of_symb] = '\0';

            num_of_ptr++;
        }

    }
}

// TODO assert(tp) не хватает везде
FILE* open_file(text_params* tp)
{
    const char* path_to_file = "Mockingbird.txt";

    tp -> file = fopen(path_to_file, "r");

    assert(tp -> file != NULL);
    assert(ferror(tp -> file) == 0); // красава!

    return tp -> file;
}

text_params constructur_text_params()
{
    text_params tp = {};

    open_file(&tp);

    tp.len_buff = count_symbls(tp.file);

    // printf("%zu\n", tp.len_buff);

    tp.buff = (char*) calloc(tp.len_buff + 1, sizeof(char));

    fread(tp.buff, sizeof(char), tp.len_buff, tp.file);

    tp.quantity_strs = count_strs(tp.buff, tp.len_buff); 

    //printf("%zu\n", tp.quantity_strs);

    tp.arr_of_ptrs = (str*) calloc(tp.quantity_strs, sizeof(str));

    assert(tp.arr_of_ptrs != NULL);

    split_lines(&tp);

    return tp;
}

void print_arr(text_params* tp)
{
    // TODO сделай отдельную функцию, которая красит вывод
    // printf_red("Original text %d", 1);
    // va_arg list: vprintf();
    printf("\x1B[4;33mOriginal text:\x1B[0;37m\n");

    // TODO у тебя строки оканчиваются \0, эффективнее строку сразу печатать, а потом \n писать
    for(size_t num_of_symb = 0; num_of_symb < tp -> len_buff; num_of_symb++)
    {
        //fprintf(stdout, "%c", tp -> buff[num_of_symb]);

        if(tp -> buff[num_of_symb] == '\0')
        {
            putchar('\n');
        }
        else
        {
            putchar(tp -> buff[num_of_symb]);
        }
    }

    putchar('\n');
}

void print_ptrs(text_params* tp)
{
    for(size_t num_of_ptr = 0; num_of_ptr < tp -> quantity_strs; num_of_ptr++)
    {
        printf("%s\n", tp -> arr_of_ptrs[num_of_ptr].begin);
    }
}

// TODO нахуй ты это написал и не используешь?
// вообще вот эта функция должна поочерёдно каждое поле проинициализировать,
// а уже потом всё разом сунуть в структуру и вернуть. Доёб к структуре проекта.
// text_params constructor_text_params(FILE* name_file, size_t len_buff, size_t quantity_strs,
//                                     char* buff,  char* arr_begining_str, char* arr_end_str)
// {
//     text_params constructor_params = {};

//     constructor_params.file               = name_file;
//     constructor_params.len_buff           = len_buff;
//     constructor_params.quantity_strs      = quantity_strs;
//     constructor_params.buff               = buff;
//     constructor_params.arr_of_ptrs->begin = arr_begining_str;
//     constructor_params.arr_of_ptrs->end   = arr_end_str;

//     return constructor_params;
// }

void destructor_text_params(text_params* tp)
{
    free(tp -> buff);
    free(tp -> arr_of_ptrs);
}