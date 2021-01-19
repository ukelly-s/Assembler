#include "asm.h"
#include "list.h"
#include "op.h"
#include "op_struct.h"
#include "util.h"
#include "io_.h"
#include "hash_map.h"
#include <fcntl.h>
#include <stdlib.h>

//debug
#include <unistd.h>
#include <stdio.h>
#include "io_.h"

static t_parse		*new_parse(void)
{
	t_parse *g;

	g = malloc(sizeof(t_parse));
	ft_assert(g != NULL, __func__, "malloc error");
	g->name = FLAG_DEFAULT;
	g->comment = FLAG_DEFAULT;
	g->header = malloc(sizeof(t_header));
	ft_assert(g->header != NULL, __func__, "malloc error");
	g->header->magic = rev_bytes(COREWAR_EXEC_MAGIC);
	g->header->prog_size = 0; //fixme debug
	g->byte_str = NULL;
	return (g);
}

void	assembler(char *filename)
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
		;
	parse(fd, g, info_operations, info_mark);
	translation_bytecode(info_operations, info_mark, g);
//	filename = replace_extension(filename, ".s", ".cor");
	if ((fd = open("test_header.cor", O_CREAT | O_TRUNC | O_WRONLY | O_APPEND, 0644)) == -1)
	    ; //error(ERR_CREATE_FILE);
	write(fd, g->header, sizeof(t_header));
    g->header->prog_size = rev_bytes(g->header->prog_size);
	write(fd, g->byte_str, g->header->prog_size);
	hashmap_destroy(&info_mark, NULL);
	free(g->byte_str);
	free(g->header);
	free(g);
	list_clear(&info_operations, free_cmd);
	ft_putstr("Writing output program to ");
	ft_putstr(filename);
}
