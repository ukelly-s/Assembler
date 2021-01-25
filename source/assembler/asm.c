/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:44:27 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 16:44:29 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_errors.h"
#include "util.h"
#include <fcntl.h>
#include <stdlib.h>
#include <ft_printf.h>
#include <unistd.h>

static t_parse	*new_parse(void)
{
	t_parse	*g;

	g = malloc(sizeof(t_parse));
	ft_assert(g != NULL, __func__, "malloc error");
	g->name = FLAG_DEFAULT;
	g->comment = FLAG_DEFAULT;
	g->header = malloc(sizeof(t_header));
	ft_assert(g->header != NULL, __func__, "malloc error");
	g->header->magic = rev_bytes(COREWAR_EXEC_MAGIC);
	g->header->prog_size = 0;
	g->byte_str = NULL;
	return (g);
}

static void		free_all_struct(t_parse *g, t_list *info_operations,
									t_hashmap *info_mark)
{
	hashmap_destroy(&info_mark, NULL);
	free(g->byte_str);
	free(g->header);
	free(g);
	list_clear(&info_operations, free_cmd);
}

void			assembler(char *filename)
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
		ft_kill(ERR_OPEN_FILE, NULL, __func__, __FILE__);
	parse(fd, g, info_operations, info_mark);
	translation_bytecode(info_operations, info_mark, g);
	filename = replace_extension(filename, ".s", ".cor");
	if ((fd = open(filename, O_CREAT | O_TRUNC
										| O_WRONLY | O_APPEND, 0644)) == -1)
		ft_kill(ERR_CREATE_FILE, NULL, __func__, __FILE__);
	write(fd, g->header, sizeof(t_header));
	g->header->prog_size = rev_bytes(g->header->prog_size);
	write(fd, g->byte_str, g->header->prog_size);
	free_all_struct(g, info_operations, info_mark);
	ft_printf("Writing output program to %s", filename);
	free(filename);
}
