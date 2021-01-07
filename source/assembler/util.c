#include "asm.h"
#include <string.h>

static int		len_clear_line(char *str)
{
	register int	i;

	i = 0;
	while (*str != '\0')
	{
		if(*str != ' ' && *str != '\t')
			i++;
		str++;
	}
	return (i);
}

char	*clear_line(char *str)
{
	char			*line;
	char			*tmp;
	int 			len;
	register int	i;

	i = 0;
	if ((tmp = ft_strchr(str, COMMENT_CHAR)) != NULL ||
		(tmp = ft_strchr(str, ALT_COMMENT_CHAR)) != NULL)
		ft_bzero(tmp, ft_strlen(tmp));
	len = len_clear_line(str);
	//fixme захерачить сюда проверку если нашли двоеточие то проверяем если перед ним нет пробела или таба то это метка
	//fixme выпарсиваем нахрен метку иначе это скорее всего операция
	line = malloc(sizeof(char) * (len + 1));
	tmp = str;
	while (*str != '\0')
	{
		if(*str != ' ' && *str != '\t')
			line[i++] = *str;
		str++;
	}
	free(tmp);
	line[i] = '\0';
	ft_putstr(line);
	return (line);
}

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (strncmp(s1, s2, n) == 0)//fixme
		return (1);
	return (0);
}
