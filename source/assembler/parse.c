#include "asm.h"
#include <string.h>

static t_line_type	get_line_type(char *line)
{
	//char	*tmp;

	if (!ft_strnequ(NAME_CMD_STRING, line, 5))
		return (LINE_NAME);
	else if (!ft_strnequ(COMMENT_CMD_STRING, line, 8))
		return (LINE_COMMENT);
//	else if ()
//		;
	else if (!*line)
		ft_kill("ERROR", NULL, __func__, __FILE__);
	return (LINE_UNDEFINED);
}

int 		get_line(int fd, char *line)
{
	char	*tmp;

	if (get_next_line(fd, &line) < 0)
		ft_kill("ERROR", NULL, __func__, __FILE__);
	if ((tmp = ft_strchr(line, COMMENT_CHAR)) != NULL ||
			(tmp = ft_strchr(line, ALT_COMMENT_CHAR)) != NULL)
		clean_line_no_comments(tmp, line);//todo ф-я которая обрежит коммент

	return (0);
	//обрезать коммент если есть COMMENT_CHAR или ALT_COMMENT_CHAR
	//если пустая строка или только строка с комментами, то пропускаем и ещё раз запускаем get_line
}

void		parse(int fd)//todo
{
	t_list		*input;
	t_line_type line_type;
	char		*line;

	while (get_line(fd, &line) == 0)
	{
		line_type = get_line_type(g_clear_line);
		//list_push_back(input, line);
		if (line_type == LINE_NAME)
			write(1, "name", 4);
		else if (line_type == LINE_COMMENT)
			write(1, "comment", 7);
		else if (line_type == LINE_OPERATION)
			write(1, "operation", 9);
		else if (line_type == LINE_ARGUMENT)
			write(1, "argument", 8);
		else
			ft_kill("ERROR", NULL, __func__, __FILE__);
	}
}
