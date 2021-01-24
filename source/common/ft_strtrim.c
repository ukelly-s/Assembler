/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:04:50 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 20:04:52 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "list.h"
#include "mem.h"
#include "str.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	if (dst == NULL || src == NULL)
		return (0);
	len = ft_strlen(src);
	if (size > len + 1)
		ft_memcpy(dst, src, len + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (len);
}

static char		*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 == 0)
		return (NULL);
	str = (char*)malloc(size * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	return (ft_memset(str, '\0', size + 1));
}

static size_t	ft_lensp(char const *src)
{
	size_t	len;
	size_t	i;

	if (*src == '\0')
		return (0);
	len = ft_strlen(src) - 1;
	i = 0;
	while (src[len] == ' ' || src[len] == '\n' || src[len] == '\t')
	{
		i++;
		len--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;

	str = NULL;
	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s) - ft_lensp(s);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
