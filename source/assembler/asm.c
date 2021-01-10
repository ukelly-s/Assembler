#include "asm.h"


static t_parse		*new_parse(void)
{
	t_parse *g;

	g = malloc(sizeof(t_parse));
	ft_assert(g != NULL, __func__, "malloc error");
	g->name = FLAG_DEFAULT;
	g->comment = FLAG_DEFAULT;
	g->header = malloc(sizeof(t_header));
	ft_assert(g->header != NULL, __func__, "malloc error");
	g->header->magic = COREWAR_EXEC_MAGIC;
	g->header->prog_size = 0;
	return (g);
}

static t_strbag2	*new_lexer(void)
{
	t_strbag2 *g;

	g = malloc(sizeof(t_strbag2 ));
	ft_assert(g != NULL, __func__, "malloc error");
	g->cmd = list_new();
	ft_assert(g->cmd != NULL, __func__, "malloc error");
	g->label = list_new();
	ft_assert(g->label != NULL, __func__, "malloc error");
	return (g);
}

void	*assembler(char *filename)
{
	int			fd;
	t_parse		*g;
	t_strbag2	*all_str;

	g = new_parse();
	all_str = new_lexer();
	if ((fd = open(filename, O_RDONLY)) == -1)
		;//error(ERR_OPEN_FILE)
	parse(fd, g, all_str);
//	filename = replace_extension(filename, ".s", ".cor");
//	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
//	    ; //error(ERR_CREATE_FILE);
	//bite code record in file
	free(g->header);//TODO
	free(g);//fixme
	ft_putstr("Writing output program to ");
	ft_putstr(filename);
}

