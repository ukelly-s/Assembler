#include "asm.h"

void	*assembler(char *filename)
{
	int		fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		;//error(ERR_OPEN_FILE)
	parse(fd);
//	filename = replace_extension(filename, ".s", ".cor");
//	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
//	    ; //error(ERR_CREATE_FILE);
	//bite code record in file
	ft_putstr("Writing output program to ");
	ft_putstr(filename);
}

