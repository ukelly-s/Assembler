#include "asm.h"

int 	get_line(int fd, char *line)
{}

void	parse(int fd)//todo
{
	t_list		*input;
	t_line_type line_type;
	char		*line;

	while (get_line(fd, &line) > 0)
	{
		//line_type = get_line_type(line);
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