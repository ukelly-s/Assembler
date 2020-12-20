#include "asm.h"
#include <string.h>

static char *array_words_to_string(char **str, int len_str, int count_words)
{
	char	*line;
	char	*tmp;
	int		i;
	int 	len;

	i = 0;
	len = 0;
	line = malloc(sizeof(char) * (len_str + count_words));
	tmp = line;
	while (i < count_words)
	{
		strcat(line, str[i]);
		len = ft_strlen(str[i]) + len;
		i++;
		if (i < count_words)
			line[len] = ' ';
	}
	return (tmp);
}
void	clean_line_no_comments(char *tmp, char *line)//todo ф-я которая обрежит коммент
{
	int		len;
	char	**str;
	int		words;
	char **buff;

	words = 0;
	len = ft_strlen(tmp);
	ft_bzero(tmp, len);
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
	//думала потом в line с одним пробелом запихнуть слова из массива
	g_clear_line = array_words_to_string(buff, len, words);
}

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (strncmp(s1, s2, n) == 0)//fixme
		return (1);
	return (0);
}
