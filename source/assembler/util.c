#include "asm.h"
#include <string.h>

char *array_words_to_string(char **str, int len_str, int count_words)
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

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (strncmp(s1, s2, n) == 0)//fixme
		return (1);
	return (0);
}
