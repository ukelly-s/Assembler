#include "asm.h"

int 	get_line(int fd, char *line, t_line_type line_type)
{
	if (get_next_line(fd, &line) < 0)
		ft_kill("ERROR", NULL, __func__, __FILE__);
	//обрезать коммент если есть COMMENT_CHAR или ALT_COMMENT_CHAR
	//если пустая строка или только строка с комментами, то пропускаем и ещё раз запускаем get_line
}

void	parse(int fd)//todo
{
	t_list		*input;
	t_line_type line_type;
	char		*line;

	while (get_line(fd, &line, line_type) > 0)
	{
		list_push_back(input, line);
		if (line_type == LINE_NAME)
			;
		else if (line_type == LINE_COMMENT)
			;
		else if (line_type == LINE_OPERATION)
			;
		else if (line_type == LINE_ARGUMENT)
			;
		else
			ft_kill("ERROR", NULL, __func__, __FILE__);
	}
	return ;
}
