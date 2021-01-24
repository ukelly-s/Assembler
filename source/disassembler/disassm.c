/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gimad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:33:59 by sberic            #+#    #+#             */
/*   Updated: 2020/12/21 17:41:51 by Gimad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	*disassembler(char *filename)
{
	int			fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_kill("Error", NULL, __func__, __FILE__);
	filename = replace_extension(filename, ".s", ".cor");
	if ((fd = open(filename, O_CREAT | O_TRUNC
						| O_WRONLY | O_APPEND, 0644)) == -1)
		ft_kill(ERR_CREATE_FILE, NULL, __func__, __FILE__);
	ft_printf("Writing output program to %s \n", filename);
	free(filename);
}
