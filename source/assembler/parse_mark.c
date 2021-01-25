/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mark.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:30:12 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/24 19:30:15 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "hash_map.h"
#include "list.h"
#include "str.h"

void	parse_mark(char *str, t_hashmap *info_mark, t_parse *g)
{
	if (hashmap_get(info_mark, str, ft_strlen(str) - 1) != NULL)
		return ;
	hashmap_put(info_mark, str, ft_strlen(str) - 1,
				(void*)(long long)g->header->prog_size);
}
