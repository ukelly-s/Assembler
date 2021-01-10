#include "command.h"

/////lft///

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

int					ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*arr;
	unsigned char	*arr2;
	size_t			i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	arr = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	while ((arr[i] == arr2[i]) && arr[i] && arr2[i] && i < n)
	{
		if (i + 1 == n)
			break ;
		++i;
	}
	if (arr[i] == arr2[i])
	{
		return (1);
	}
	else
	{
		return (0);
	}
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
/////lft///

//for cmd

int     add_cmd_mem(t_cmd **cmd)
{
	t_cmd       *tmp;

	tmp = *cmd;
	if(!(*cmd))
	{
		if (!(*cmd = ft_memalloc(sizeof(t_cmd))))
			return (0);
	}
	else
	{
		while (tmp)
			tmp = tmp->next;
		if (!(tmp->next = ft_memalloc(sizeof(t_cmd))))
			return (0);
	}
	return (1);
}