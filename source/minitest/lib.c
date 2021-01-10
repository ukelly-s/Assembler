#include "lexer.h"
//#include "libft.h"
#include <stdio.h> // debug
#include <stdlib.h>

///lft///
static int	nbr_len(unsigned long long n)
{
	int len;

	len = 1;
	while ((n /= 10) != 0)
		len++;
	return (len);
}

long long	ft_atol(const char *str)
{
	int					sign;
	unsigned long long	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? (-1) : (1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
		if (res > LONG_LONG_MAX && sign > 0)
			return (-1);
		if (res > 0)
			if (res - 1 > LONG_LONG_MAX && sign < 0)
				return (0);
		if (nbr_len(res) >= 19 && (*str >= '0' && *str <= '9'))
			return ((sign > 0) ? (-1) : (0));
	}
	return ((long long)res * sign);
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