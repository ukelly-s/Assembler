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
#include <stdbool.h>
#include "str.h"
#include "io_.h"

static _Bool	check_name_the_file(char *name_the_file, char *file_extension)//fixed
{
	char	*tmp;

	tmp = strrchr(name_the_file, '.');

//	while (*tmp != '\0') - тут сега, strchr может возвр налл
//	{
//		if (*tmp != *file_extension)
//			return (false);
//		tmp++;
//		file_extension++;
//	}
//	return (true);
	return (ft_strequ(tmp, file_extension));
}

int		main(int ac, char **av)
{
	if (ac == 2 && check_name_the_file(*(av + 1), ".s"))
		assembler(*(av + 1));
	else if (ac == 2 && check_name_the_file(*(av + 1), ".cor"))
		;//disassembler(*(av + 1));
	else
		ft_putstr("usage: ./asm file_name\n");
	return (0);
}
