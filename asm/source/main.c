
#include "asm.h"
# include <stdbool.h>

t_bool check_name_the_file(char *name_the_file, char *file_extension)
{

}

int main(int ac, char **av)
{
    if (ac == 2 && check_name_the_file(*(av + 1), ".as"))
        ;
    else if (ac == 2 && check_name_the_file(*(av + 1), ".cor"))
        ;
    else
        ;
    return (0);
}