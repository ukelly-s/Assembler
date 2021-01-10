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

# define L 'l'
# define S 's'
# define A 'a'
# define O 'o'
# define X 'x'
# define Z 'z'
# define F 'f'

# define LIVE "live"
# define LD "ld"
# define LDI "ldi"
# define LLD "lld"
# define LLDI "lldi"
# define LFORK "lfork"
# define ST "st"
# define STI "sti"
# define SUB "sub"
# define ADD "add"
# define AND "and"
# define AFF "aff"
# define OR "or"
# define XOR "xor"
# define ZJMP "zjmp"
# define FORK "fork"

typedef struct	s_strtype{
	int			cmd;
	int			label;
	int			hash_comm;
}				t_strtype;

#endif
