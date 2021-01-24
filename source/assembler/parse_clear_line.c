/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clear_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:28:52 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 19:28:54 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "asm_errors.h"
#include "list.h"
#include "mem.h"
#include "str.h"
#include "util.h"
#include "op.h"

static int		len_clear_line(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\t')
			i++;
		str++;
	}
	return (i);
}

static int		f_len_mark(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] != LABEL_CHAR)
	{
		if (str[j] == ' ')
			ft_kill(ERR_SYNTAX, NULL, __func__, __FILE__);
		j++;
		i++;
	}
	return (i);
}

static char		*clear_line_operation(char **str)
{
	char	*line;
	char	*tmp;
	int		len;
	int		check_space;
	int		i;

	i = 0;
	check_space = 0;
	len = len_clear_line(*str) + 1;
	line = malloc(sizeof(char) * (len + 1));
	tmp = *str;
	while (**str != '\0')
	{
		if(**str != ' ' && **str != '\t')
			line[i++] = **str;
		if ((**str == ' ' || **str == '\t') && check_space++ == 0)
			line[i++] = ' ';
		(*str)++;
	}
	free(tmp);
	tmp = NULL;
	line[i] = '\0';
	return (line);
}

static char		*clear_line_mark(char **str, int len)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		line[i] = (*str)[i];
		(*str)[i] = ' ';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char			*clear_line(char **str)
{
	char	*line;
	char	*tmp;
	int		len_mark;

	if ((tmp = ft_strchr(*str, COMMENT_CHAR)) != NULL ||
		(tmp = ft_strchr(*str, ALT_COMMENT_CHAR)) != NULL)
		ft_bzero(tmp, ft_strlen(tmp));
	if (!**str && !(line = ft_memalloc(1)))
		free (*str);
	else if (mark_operation_type(*str) == LINE_MARK)
	{
		len_mark = f_len_mark(*str) + 1;
		line = clear_line_mark(str, len_mark);
		tmp = ft_strtrim(*str);
		free(*str);
		if (*tmp == '\0')
			free(tmp);
		else
			*str = tmp;
	}
	else
		line = clear_line_operation(str);
	return (line);
}
