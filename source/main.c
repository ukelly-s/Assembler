/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 06:14:23 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/10 06:14:24 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <string.h>
#include "str.h"
#include "io_.h"

static _Bool	check_name_the_file(char *name_the_file, char *file_extension)
{
	char	*tmp;

	tmp = strrchr(name_the_file, '.');
	return (ft_strequ(tmp, file_extension));
}

int		main(int ac, char **av)
{
	if (ac == 2 && check_name_the_file(*(av + 1), ".s"))
		assembler(*(av + 1));
	else
		ft_putstr("usage: ./asm file_name\n");
	return (0);
}
