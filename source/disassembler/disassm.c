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

void	*disassembler(char  *filename)
{
	int  fd;
	if ((fd = open(filename, O_RDONLY)) == -1)
		;//error(ERR_OPEN_FILE)
	parse(fd);
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		;//error(ERR_CREATE_FILE);
	ft_putstr("Writing output program to ");
	ft_putstr(filename);
}	
