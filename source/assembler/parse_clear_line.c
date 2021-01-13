#include "asm.h"
# include "list.h"
# include "mem.h"
# include "str.h"
# include "op.h"

static int		len_clear_line(char *str)
{
	register int		i;

	i = 0;
	while (*str != '\0')
	{
		if(*str != ' ' && *str != '\t')
			i++;
		str++;
	}
	return (i);
}

static int		f_len_mark(char *str)
{
	register int		i;

	i = 0;
	while(*str++ != LABEL_CHAR)
		i++;
	return (i);
}

static char		*clear_line_operation(char **str)
{
	char				*line;
	char				*tmp;
	int					len;
	register int		i;

	i = 0;
	len = len_clear_line(*str);
	line = malloc(sizeof(char) * (len + 1));
	tmp = *str;
	while (**str != '\0')
	{
		if(**str != ' ' && **str != '\t')
			line[i++] = **str;
		(*str)++;
	}
	free(tmp);
	tmp = NULL;
	line[i] = '\0';
	return (line);
}

static char		*clear_line_mark(char **str, int len)
{
	char			*line;
	register int	i;

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
	if (mark_operation_type(*str) == LINE_MARK)
	{
		len_mark = f_len_mark(*str) + 1;
		line = clear_line_mark(str, len_mark);
	}
	else
	{
		line = clear_line_operation(str);
		*str = NULL;
	}
	return (line);
}
