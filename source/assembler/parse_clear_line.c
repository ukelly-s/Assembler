#include "asm.h"
#include "asm_errors.h"
# include "list.h"
# include "mem.h"
# include "str.h"
# include "util.h"
# include "op.h"

static int		len_clear_line(char *str)
{
	int		i;

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
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(str[j] != LABEL_CHAR)
	{
		if (str[j] == ' ')
			ft_kill(ERR_SYNTAX, NULL, __func__, __FILE__);
		j++;
		i++;
	}
	return (i);
}

#include <unistd.h>
#include "io_.h"
static char		*clear_line_operation(char **str)
{
	char	*line;
	int		len;
	int		check_space;
	int		i;
	int		j;

	i = 0;
	j = 0;
	check_space = 0;
	len = len_clear_line(*str) + 1;
	line = malloc(sizeof(char) * (len + 1));
	while (str[0][j] != '\0')
	{
		if(str[0][j] != ' ' && str[0][j] != '\t')
			line[i++] = str[0][j];
		if ((str[0][j] == ' ' || str[0][j] == '\t') && check_space++ == 0)
			line[i++] = ' ';
		j++;
	}
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
	char	*line;//TODO не могу нихуя понять на карте tests/asm/valid/gedeon.s тут появляется в памяти какая-то хрень
	char	*tmp;
	int		len_mark;

	if ((tmp = ft_strchr(*str, COMMENT_CHAR)) != NULL ||
		(tmp = ft_strchr(*str, ALT_COMMENT_CHAR)) != NULL)
			ft_bzero(tmp, ft_strlen(tmp));
	if (!**str)
		line = ft_memalloc(1);//todo с null никак нельзя
	else if (mark_operation_type(*str) == LINE_MARK)
	{
		len_mark = f_len_mark(*str) + 1;
		line = clear_line_mark(str, len_mark);
		if (*(tmp = ft_strtrim(*str)) != '\0')
		{
			free(*str);
			*str = tmp;
			return (line);
		}
		free(tmp);
	}
	else
		line = clear_line_operation(str);
	free(*str);
	*str = NULL;
	return (line);
}
