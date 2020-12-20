#include "asm.h"
#include <string.h>

static t_line_type	get_line_type(char *line)
{
	//char	*tmp;

	if (ft_strnequ(NAME_CMD_STRING, line, 5))
		return (LINE_NAME);
	else if (ft_strnequ(COMMENT_CMD_STRING, line, 8))
		return (LINE_COMMENT);
//	else if ()
//		;
	else if (!*line)
		return (LINE_UNDEFINED);
	return (LINE_UNDEFINED);
}

static void	clean_line(char *tmp, char *line)//todo ф-я которая обрежит коммент
{
	int		len;
	char	**str;
	int		words;
	char **buff;

	words = 0;
	len = 0;
	str = ft_strsplit(line, ' ');
	buff = str;
	free(line);
	while (*str != NULL)
	{
		words++;
		len = ft_strlen(*str) + len;
		str++;
	}
	g_clear_line = array_words_to_string(buff, len, words);

}

int 		get_line(int fd, char *line)
{
	char	*tmp;

	if (get_next_line(fd, &line) < 0)
		ft_kill("ERROR", NULL, __func__, __FILE__);
	if ((tmp = ft_strchr(line, COMMENT_CHAR)) != NULL ||
			(tmp = ft_strchr(line, ALT_COMMENT_CHAR)) != NULL)
		ft_bzero(tmp, ft_strlen(tmp));
		//clean_line_no_comments(tmp, line);//todo ф-я которая обрежит коммент
	clean_line(tmp, line);
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
		if (line_type != LINE_UNDEFINED)
			free(g_clear_line);
	}
}
