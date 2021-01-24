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

# include <stdint.h>
# include	"list.h"
# include <mem.h>

typedef struct	s_cmd
{
	uint8_t		code;
	uint8_t		args_types[3];
	int32_t 	args_value[3];
	char 		*mark[3];
	uint32_t	size_op;
}				t_cmd;

typedef union	s_code4b
{
	int32_t		digit;
	uint8_t 	letter[4];
}				t_code4b;

typedef union	s_code2b
{
	int16_t		digit;
	uint8_t		letter[2];
}				t_code2b;

void			free_cmd(t_cmd *cmd);
uint32_t		rev_bytes(uint32_t define);
void			get_to_4byte(t_byte *str, int32_t args_value);
void			get_to_2byte(t_byte *str, int32_t args_value);


#endif
