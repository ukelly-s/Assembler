/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger_log_alias.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 16:43:23 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/30 16:43:25 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "logger_.h"
#include "logger.h"

void		log_trace(const char *func, const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	do_log(TRACE, func, fmt, ap);
	va_end(ap);
}

void		log_debug(const char *func, const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	do_log(DEBUG, func, fmt, ap);
	va_end(ap);
}

void		log_info(const char *func, const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	do_log(INFO, func, fmt, ap);
	va_end(ap);
}

void		log_warn(const char *func, const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	do_log(WARN, func, fmt, ap);
	va_end(ap);
}

void		log_error(const char *func, const char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	do_log(ERROR, func, fmt, ap);
	va_end(ap);
}
