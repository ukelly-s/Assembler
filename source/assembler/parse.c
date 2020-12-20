#include "asm.h"
#include <string.h>

static void	clean_line_no_comments(char *tmp, char *line)
{
	int		len;
	char	**str;
	int		words;
	char	**buff;
	words = 0;
	len = ft_strlen(tmp);
	ft_bzero(tmp, len);
	len = 0;
	str = ft_strsplit(line, ' ');
	free(line);
	buff = str;
	while (*buff != NULL)
	{
		words++;
		len = ft_strlen(*buff) + len;
		buff++;
	}
	line = malloc(sizeof(char) * (len + words));
	//думала потом в line с одним пробелом запихнуть слова из массива

}

int 		get_line(int fd, char *line, t_line_type line_type)
{
	char	*tmp;

	if (get_next_line(fd, &line) < 0)
		ft_kill("ERROR", NULL, __func__, __FILE__);
	if ((tmp = ft_strchr(line, COMMENT_CHAR)) != NULL ||
			(tmp = ft_strchr(line, ALT_COMMENT_CHAR)) != NULL)
		clean_line_no_comments(tmp, line);//todo ф-я которая обрежит коммент

	//обрезать коммент если есть COMMENT_CHAR или ALT_COMMENT_CHAR
	//если пустая строка или только строка с комментами, то пропускаем и ещё раз запускаем get_line
}

void		parse(int fd)//todo
{
	t_list		*input;
	t_line_type line_type;
	char		*line;

	while (get_line(fd, &line, line_type) > 0)
	{
		list_push_back(input, line);
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
