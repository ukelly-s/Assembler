/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:57:52 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/30 15:57:53 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	ft_strstart(const char *str, const char *prefix)
{
	return (ft_strnequ(str, prefix, ft_strlen(prefix)));
}
