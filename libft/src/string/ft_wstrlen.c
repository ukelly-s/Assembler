/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:53:53 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/30 16:53:55 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wctype.h>

size_t	ft_wstrlen(const wint_t *s)
{
	register size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len++;
		len += *s > 0xFFFF;
		len += *s > 0x7FF;
		len += *s > 0x7F;
		++s;
	}
	return (len);
}
