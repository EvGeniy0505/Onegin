#include "read_from_file.h"


int main()
{
    struct text_params tp = read_from_file();

    destructor_text_params(&tp);
    
    return 0;
}