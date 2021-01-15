#include "asm.h"
#include "asm_errors.h"
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include "array_list.h"
# include "conv.h"
# include "hash_map.h"
# include "io_.h"
# include "list.h"
# include "math.h"
# include "mem.h"
# include "str.h"
# include "util.h"
# include "op.h"
# include "op_struct.h"
# include "lexer.h"

int					get_number_operation(const char *str)
{
	register int		i;
	int					check;
	int					len;

	i = 1;
	while (i < 17)
	{
		len = ft_strlen(g_op[i].name);
		check = ft_strnequ(str, g_op[i].name, len);
		if (check == 1 && (str[len - 1] == 'i' || str[len] == 'i'))
		{
			if (g_op[i].name[len - 1] == 'i')
				return (i);
		}
		else if (check == 1)
			return (i);
		i++;
	}
	return (-1);
}

static t_line_type	get_line_type(const char *line, t_parse *g)
{
	char	*tmp;

	if (ft_strnequ(NAME_CMD_STRING, line, 5) && g->name == FLAG_DEFAULT)
	{
		g->name = FLAG_NAME;
		return (LINE_NAME);
	}
	else if (ft_strnequ(COMMENT_CMD_STRING, line, 8)
			 && g->comment == FLAG_DEFAULT)
	{
		g->comment = FLAG_COMMENT;
		return (LINE_COMMENT);
	}
	else if ((tmp = ft_strchr(line, LABEL_CHAR)) != NULL && (*(++tmp) == '\0'))
		return (LINE_MARK);
	else if (get_number_operation(line) != -1)
		return (LINE_OPERATION);
	else if (!*line || line[0] == COMMENT_CHAR || line[0] == ALT_COMMENT_CHAR)
		return (LINE_EMPTY);
	return (LINE_UNDEFINED);
}

static char			*get_line_name_comment(int fd, char *line)
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
			ft_kill(ERR_READINING, NULL, __func__, __FILE__);
		tmp = line ? ft_strjoin(line, buff) : ft_strdup(buff);
		free(buff);
		free(line);
		line = tmp;
	}
	return (line);
}

int					get_line(int fd, char **line)//fixme
{
	char				*tmp;
	static char			*buff;
	register int		i;

	if (buff != NULL && (*line = clear_line(&buff)))
		return (1);
	if ((i = get_next_line(fd, &tmp)) < 0)
		ft_kill(ERR_READINING, NULL, __func__, __FILE__);
	if (i == 0 || ((!*tmp || tmp[0] == COMMENT_CHAR
					|| tmp[0] == ALT_COMMENT_CHAR) && (*line = tmp)))
		return (i);
	buff = ft_strtrim(tmp);
	free(tmp);
	if (ft_strnequ(NAME_CMD_STRING, buff, 5) ||
		(ft_strnequ(COMMENT_CMD_STRING, buff, 8)))
	{
		if (ft_strchr(buff, '\"') == NULL)
			ft_kill(ERR_SYNTAX, NULL, __func__, __FILE__);
		*line = get_line_name_comment(fd, buff);
		buff = NULL;
	}
	else
		*line = clear_line(&buff);
	return (i);
}

void				parse(int fd, t_parse *g, t_list *info_operations,
						  t_hashmap *info_mark)
{
	t_line_type	line_type;
	char		*line;

	while (get_line(fd, &line) > 0)
	{
		line_type = get_line_type(line, g);
		if (line_type == LINE_NAME)
			parse_name(line, g);
		else if (line_type == LINE_COMMENT)
			parse_comment(line, g);
		else if (line_type == LINE_OPERATION)
			parse_operation(line, info_operations, g);//todo
		else if (line_type == LINE_MARK)
			parse_mark(line, info_mark, g);//todo
		else if (line_type == LINE_UNDEFINED)
			ft_kill(ERR_INV_LINE, NULL, __func__, __FILE__);
		free(line);
		line = NULL;
		write(1, "\n", 1);//fixme delete
	}
}
