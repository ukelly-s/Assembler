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
	uint8_t	args_value[3];
	char		*mark;
}				t_cmd;

/*
** find_cmd.c
*/

//void			write_cmd_fork(char *s, t_cmd **cmd_fork);
//int				cmd_l(char *s, t_cmd **cmd);
//int				cmd_s(char *s, t_cmd **cmd);
//int				cmd_a(char *s, t_cmd **cmd);
//int				find_cmd_tree(char *s, t_cmd **cmd);

/*
** labeler.c
*/

//int				find_label(char *s, t_label **label);
//t_label			*new_lable(char *s);
//void			add_label(char *s, t_label**label);
//int				labeler(char *s, t_label *label);

/*
** labelfind.c
*/

int				labeler2(char *s, t_list *label);

/*
**live.c
*/

//void			do_livejmpfork(char *s, t_cmd **cmd, int8_t cmdind);
/*
** lex.c
*/

//int				add_cmd_mem(t_cmd **cmd);
//int				lexer(char *s, t_strbag2 *all_str);

#endif
