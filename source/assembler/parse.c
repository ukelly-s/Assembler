#include "asm.h"
#include "asm_errors.h"
#include <string.h>

static int			find_cmd(char *s)
{
	if (ft_strnequ(s, LIVE, 4) || ft_strnequ(s, LD, 2)
		|| ft_strnequ(s, LDI, 3) || ft_strnequ(s, LLD, 3)
		|| ft_strnequ(s, LLDI, 4) || ft_strnequ(s, LFORK, 5)
		|| ft_strnequ(s, ST, 2) || ft_strnequ(s, STI, 3 )
		|| ft_strnequ(s, SUB, 3) || ft_strnequ(s, ADD, 3)
		|| ft_strnequ(s, AND, 3) || ft_strnequ(s, AFF, 3)
		|| ft_strnequ(s, OR, 2) || ft_strnequ(s, XOR, 3)
		|| ft_strnequ(s, ZJMP, 4) || ft_strnequ(s, FORK, 4))
		return (1);
	return (0);
}

static t_line_type	get_line_type(const char *line, t_parse *g)
{
	if (ft_strnequ(NAME_CMD_STRING, line, 5) && g->comment == FLAG_DEFAULT)
	{
		g->name = FLAG_NAME;
		return (LINE_NAME);
	}
	else if (ft_strnequ(COMMENT_CMD_STRING, line, 8) && g->comment == FLAG_DEFAULT)
	{
		g->comment = FLAG_COMMENT;
		return (LINE_COMMENT);
	}
	else if (find_cmd(line) == 1)//todo распарсивать правильно метки и операции
		return (LINE_OPERATION);
	else if (strrchr(line, ':'))
		return (LINE_ARGUMENT);
	else if (!*line)
		return (LINE_EMPTY);
	return (LINE_UNDEFINED);
}

int 		get_line(int fd, char **line)//fixme
{
	char	*tmp;
	char	*buff;

	while (get_next_line(fd, &tmp) > 0)
	{
		if (!*tmp)
			break;
		buff = ft_strtrim(tmp);
		free(tmp);
		if (ft_strnequ(NAME_CMD_STRING, buff, 5) ||
			(ft_strnequ(COMMENT_CMD_STRING, buff, 8)))
		{
			tmp = *line ? ft_strjoin(*line, buff) : ft_strdup(buff);
			if (*line)
				free(*line);
			*line = tmp;
			free(buff);
			if ((buff = ft_strchr(*line, '\"')) != NULL)
				if ((buff = ft_strchr(++buff, '\"')) != NULL)
					break;
				else
					continue;
		}
		else
			*line = clear_line(buff);
		break;
	}
	return (0);
}


void		parse(int fd, t_parse *g)//todo
{
	t_line_type line_type;
	char		*line;

	while (get_line(fd, &line) == 0)
	{
		line_type = get_line_type(line, g);
		if (line_type == LINE_NAME)
			ft_putstr(line);
		else if (line_type == LINE_COMMENT)
			ft_putstr(line);
		else if (line_type == LINE_OPERATION)
			ft_putstr(line);//todo начни ф-ю делать которая с операциями работает
		else if (line_type == LINE_ARGUMENT)
			ft_putstr(line);//todo нужно ещё что-то с метками придумать, мне в голову ничего не пришло
		else if (line_type == LINE_UNDEFINED)
			ft_kill(ERR_INV_LINE, NULL, __func__, __FILE__);
		if (line_type != LINE_EMPTY)
		{
			free(line);
			line = NULL;
		}
		write(1, "\n", 1);//todo delete
	}
}
