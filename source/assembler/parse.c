#include "asm.h"
#include <string.h>

static t_line_type	get_line_type(char *line)
{
	//char	*tmp;

	if (ft_strnequ(NAME_CMD_STRING, line, 5))
		return (LINE_NAME);
	else if (ft_strnequ(COMMENT_CMD_STRING, line, 8))
		return (LINE_COMMENT);
	else if (ft_strnequ("sti", line, 3))//todo сделать корректную проверку на то операция это или аргумент
		return (LINE_OPERATION);
//	else if (ft_strnequ("sti", line, 3))
//		return (LINE_ARGUMENT);
	else if (!*line)
		return (LINE_UNDEFINED);
	return (LINE_UNDEFINED);
}

int 		get_line(int fd, char **line)//fixme получилась хуйня, но она работает, я исправлю завтра, а то мозг не варит
{
	char	*tmp_line;//fixme убрать лишнее
	char	*tmp;//fixme отследить утечки
	char	*buff;//fixme нагородила херню, удивительно что работает

	while (get_next_line(fd, &tmp_line) > 0)
	{
		buff = ft_strtrim(tmp_line);
		free(tmp_line);
		tmp = *line ? ft_strjoin(*line, buff) : ft_strdup(buff);
		if (*line)
			free(*line);
		*line = tmp;
		if (ft_strnequ(NAME_CMD_STRING, *line, 5) ||
			(ft_strnequ(COMMENT_CMD_STRING, *line, 8)))
		{
			if ((tmp_line = ft_strchr(*line, '\"')) != NULL)
				if ((tmp_line = ft_strchr(++tmp_line, '\"')) != NULL)
					break;
				else
					continue;
		}
		if ((tmp_line = ft_strchr(*line, COMMENT_CHAR)) != NULL ||
			(tmp_line = ft_strchr(*line, ALT_COMMENT_CHAR)) != NULL)
		ft_bzero(tmp_line, ft_strlen(tmp_line));
		break;
	}
	free(buff);
	//		ft_kill("ERROR", NULL, __func__, __FILE__);
	return (0);
}


void		parse(int fd)//todo
{
	t_list		*input;
	t_line_type line_type;
	char		*line;

	while (get_line(fd, &line) == 0)
	{
		line_type = get_line_type(line);
		//list_push_back(input, line);
		if (line_type == LINE_NAME)
			write(1, "name", 4);
		else if (line_type == LINE_COMMENT)
			write(1, "comment", 7);
		else if (line_type == LINE_OPERATION)
			write(1, "operation", 9);//todo начни ф-ю делать которая с операциями работает
		else if (line_type == LINE_ARGUMENT)
			write(1, "argument", 8);//todo нужно ещё что-то с метками придумать, мне в голову ничего не пришло
		if (line_type != LINE_UNDEFINED)
		{
			free(line);
			line = NULL;
		}
	}
}
