/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 05:57:55 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/10 05:57:57 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_LEXER_H
# define ASSEMBLER_LEXER_H

# include <stdio.h> //fixme delete
# include <stdint.h>
#include	"list.h"

# define LABEL 1
# define CMD   2

# define FOUND 1
# define NOTFOUND 0

# define LIVE 0x01
# define LD 0x02
# define ST 0x03
# define ADD 0x04
# define SUB 0x05
# define AND 0x06
# define OR 0x07
# define XOR 0x08
# define ZJMP 0x09
# define LDI 0x0a
# define STI 0x0b
# define FORK 0x0c
# define LLD 0x0d
# define LLDI 0x0e
# define LFORK 0x0f
# define AFF 0x010

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

typedef struct	s_cmd
{
	uint8_t		code;
	uint8_t		args_types[3];
	uint8_t		args_value[3];
	char		*mark;
}				t_cmd;

#endif