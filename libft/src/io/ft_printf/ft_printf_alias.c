/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_alias.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:46:06 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/30 15:46:07 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int					ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(STDOUT_FILENO, format, ap));
}

int					ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

int					ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (ret);
}
