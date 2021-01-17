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
#include	"list.h"


typedef struct	s_cmd
{
	uint8_t			code;
	uint8_t			args_types[3];
	uint8_t 		byte_type;
	int32_t 		args_value[3];
	char 			*mark[3];
	uint32_t		size_op;
}				t_cmd;

#endif