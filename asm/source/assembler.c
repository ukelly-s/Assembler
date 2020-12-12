#include "asm.h"

static t_parser	*initialization(void)
{
	t_parser	*assm;

	assm = malloc(sizeof(t_parser));
	ft_assert(assm != NULL, __func__, "malloc error");
	ft_bzero(assm, 0);
	/*
	 ** иницилизируем все обёкты которые появятся в
	 */
	return (assm);
}

void 			*assembler(char *filename)
{
	int			fd;
	t_parser	*assm;

	if ((fd = open(filename, O_RDONLY)) == -1)
		;//error(ERR_OPEN_FILE)
	assm = initialization();
	assm->fd = fd;
	parse(assm);
//	filename = replace_extension(filename, ".s", ".cor");
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		;//error(ERR_CREATE_FILE);
	//bite code record in file
	ft_putstr("Writing output program to ");
	ft_putstr(filename);
}
