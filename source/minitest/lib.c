#include "lexer.h"
//#include "libft.h"
#include <stdio.h> // debug
#include <stdlib.h>

///lft///
int		            find_start_cmd(char *s)
{
	if (s[0] == L || s[0] == S
	    || s[0] == A || s[0] == O
	    || s[0] == X || s[0] == Z
	    || s[0] == F)
		return (1);
	else
		return (0);
}

void				ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	if (!n)
		return ;
	i = 0;
	arr = (unsigned char *)s;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
}

int					ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*arr;
	unsigned char	*arr2;
	size_t			i;

	if (!s1 || !s2)
		return (0);
	arr = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	i = 0;
	while ((arr[i] == arr2[i]) && arr[i] && arr2[i])
		i++;
	if (arr[i] == arr2[i])
		return (1);
	else
		return (0);
}

void	            *ft_memalloc(size_t size)
{
	unsigned char	*arr;
	size_t			i;

	if (size == 0)
		return (NULL);
	i = 0;
	if (!(arr = (unsigned char*)malloc(size)))
		return (NULL);
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void*)arr);
}

size_t				ft_strlen_prot(const char *str)
{
	size_t			i;
	unsigned char	*arr;

	if (str == NULL)
		return (0);
	i = 0;
	arr = (unsigned char*)str;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i);
}

char				*ft_strdup_prot(const char *s)
{
	size_t			i;
	char			*arr;

	i = ft_strlen_prot(s);
	if (s == NULL)
		return (NULL);
	if (!(arr = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
///lft///