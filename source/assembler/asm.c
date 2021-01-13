#include "asm.h"
#include "list.h"
#include "op.h"
#include "op_struct.h"
#include "util.h"
#include "io.h"
#include "hash_map.h"
#include <fcntl.h>
#include <stdlib.h>

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
	g->header->prog_size = 5;
	return (g);
}

void	*assembler(char *filename)
{
	int			fd;
	t_parse		*g;
	t_list		*info_operations;
	t_hashmap	*info_mark;

	g = new_parse();
	info_mark = hashmap_new();
	info_operations = list_new();
	ft_assert(info_mark != NULL && info_operations != NULL,
			  __func__, "malloc error");
	if ((fd = open(filename, O_RDONLY)) == -1)
		;//error(ERR_OPEN_FILE)
	parse(fd, g, info_operations, info_mark);
//	filename = replace_extension(filename, ".s", ".cor");
//	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
//	    ; //error(ERR_CREATE_FILE);
	//bite code record in file
	free(g->header);//TODO
	free(g);//fixme
	ft_putstr("Writing output program to ");
	ft_putstr(filename);
}
