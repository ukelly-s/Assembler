#include "asm.h"

_Bool	check_name_the_file(char *name_the_file, char *file_extension)
{
	char *tmp;
	char *buff;

	tmp = ft_strdup(name_the_file);
	ft_strrev(tmp);
	buff = tmp;
	while (*tmp != '.')
	{
		if (*tmp!= *file_extension)
		{
			free(buff);
			return (false);
		}
		tmp++;
		file_extension++;
	}
	free(buff);
	return (true);
}


int		main(int ac, char **av)
{
    if (ac == 2 && check_name_the_file(*(av + 1), "s."))
		assembler(*(av + 1));
    else if (ac == 2 && check_name_the_file(*(av + 1), "roc."))
		disassembler(*(av + 1));
    else
		ft_putstr("usage: ./asm file_name\n");
    return (0);
}