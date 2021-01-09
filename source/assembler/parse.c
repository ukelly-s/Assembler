#include "asm.h"
#include "asm_errors.h"
#include <string.h>

static int			find_cmd(const char *s)
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
	char *tmp;

	if (ft_strnequ(NAME_CMD_STRING, line, 5) && g->name == FLAG_DEFAULT)
	{
		g->name = FLAG_NAME;
		return (LINE_NAME);
	}
	else if (ft_strnequ(COMMENT_CMD_STRING, line, 8) && g->comment == FLAG_DEFAULT)
	{
		g->comment = FLAG_COMMENT;
		return (LINE_COMMENT);
	}
	else if ((tmp = ft_strchr(line, LABEL_CHAR)) != NULL && (*(++tmp) == '\0'))
		return (LINE_MARK);
	else if (find_cmd(line) == 1)
		return (LINE_OPERATION);
	else if (!*line || line[0] == COMMENT_CHAR || line[0] == ALT_COMMENT_CHAR)
		return (LINE_EMPTY);
	return (LINE_UNDEFINED);
}

static char	*get_line_name_comment(int fd, char *line)
{
	char	*tmp;
	char	*buff;
	int		i;

	i = 1;
	while (i > 0)
	{
		if ((buff = ft_strchr(line, '\"')) != NULL)
			if ((buff = ft_strchr(++buff, '\"')) != NULL)
				break;
		if (( i = get_next_line(fd, &buff)) < 0)
			ft_kill("ERROR", NULL, __func__, __FILE__);
		tmp = line ? ft_strjoin(line, buff) : ft_strdup(buff);
		free(buff);
		free(line);
		line = tmp;
	}
	return (line);
}

int 		get_line(int fd, char **line)//fixme
{
	char		*tmp;
	static char	*buff;
	int			i;

	if (buff != NULL && (*line = clear_line(&buff)))
		return (1);
	if ((i = get_next_line(fd, &tmp)) < 0)
		ft_kill("ERROR", NULL, __func__, __FILE__);
	if (i == 0)
		return (i);
	if ((!*tmp || tmp[0] == COMMENT_CHAR || tmp[0] == ALT_COMMENT_CHAR) && (*line = tmp))
		return (i);
	buff = ft_strtrim(tmp);
	free(tmp);
	if (ft_strnequ(NAME_CMD_STRING, buff, 5) ||
		(ft_strnequ(COMMENT_CMD_STRING, buff, 8)))
	{
		*line = get_line_name_comment(fd, buff);
		buff = NULL;
	}
	else
		{
		*line = clear_line(&buff);
		buff = NULL;
	}
	return (i);
}


void		parse(int fd, t_parse *g)//todo
{
	t_line_type line_type;
	char		*line;

	while (get_line(fd, &line) > 0)
	{
		line_type = get_line_type(line, g);
		if (line_type == LINE_NAME)
			ft_putstr(line);
		else if (line_type == LINE_COMMENT)
			ft_putstr(line);
		else if (line_type == LINE_OPERATION)
			ft_putstr(line);//todo начни ф-ю делать которая с операциями работает
		else if (line_type == LINE_MARK)
			ft_putstr(line);//todo нужно ещё что-то с метками придумать, мне в голову ничего не пришло
		else if (line_type == LINE_UNDEFINED)
			ft_kill(ERR_INV_LINE, NULL, __func__, __FILE__);
		free(line);
		line = NULL;
		write(1, "\n", 1);//todo delete
	}
}
