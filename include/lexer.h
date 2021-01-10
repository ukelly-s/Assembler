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
# include "array_list.h"
# include "conv.h"
# include "hash_map.h"
# include "io.h"
# include "list.h"
# include "math.h"
# include "mem.h"
# include "str.h"
# include "util.h"

# define L 'l'
# define S 's'
# define A 'a'
# define O 'o'
# define X 'x'
# define Z 'z'
# define F 'f'
# define D 'd'
# define I 'i'
# define V 'v'
# define E 'e'
# define R 'r'
# define K 'k'
# define T 't'
# define U 'u'
# define B 'b'
# define N 'n'
# define J 'j'
# define M 'm'
# define P 'p'

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

typedef struct	s_label{
	char			*name;
	int32_t			id;
	int32_t			address;   //байт сначала файла
	int32_t			n_cmd;     //номер строки прише
	struct s_label	*next;
}				t_label;

typedef struct	s_label2{
	char			*name;
	int32_t			id;
	int32_t			address;   //байт сначала файла
	int32_t			n_cmd;     //номер строки прише
}				t_label2;

typedef struct	s_cmd{
	char			*cmd;           //namecmd
	int32_t			n_cmd;         //id
	int32_t			id;            //zapasnoi
	int8_t			name_code;
	int32_t			args_type[3];  //тип аругмента, если 0 тогда нет аргумента соотв. REG_CODE,DIR_CODE,IND_CODE
	int32_t			args[3];       //сами аргументы
	int8_t			args_types_code; //тип кодов аргументов
	int32_t			args_weight[3]; //вес аргументов, если 0, то веса нет
	int32_t			args_cnt;
	struct s_cmd	*next;
}					t_cmd;

typedef struct	s_cmd2{
	char		*cmd;           //namecmd
	int32_t		n_cmd;         //id
	int32_t		id;            //zapasnoi
	int8_t		name_code;
	int32_t		args_type[3];  //тип аругмента, если 0 тогда нет аргумента соотв. REG_CODE,DIR_CODE,IND_CODE
	int32_t		args[3];       //сами аргументы
	int8_t		args_types_code; //тип кодов аргументов
	int32_t		args_weight[3]; //вес аргументов, если 0, то веса нет
	int32_t		args_cnt;
}					t_cmd2;

typedef struct	s_strbag{
	t_label		*label;
	t_cmd		*cmd;
}				t_strbag;

typedef struct	s_strbag2{
	t_list		*label;
	t_list		*cmd;
}				t_strbag2;


/*
** find_cmd.c
*/

void			write_cmd_fork(char *s, t_cmd **cmd_fork);
int				cmd_l(char *s, t_cmd **cmd);
int				cmd_s(char *s, t_cmd **cmd);
int				cmd_a(char *s, t_cmd **cmd);
int				find_cmd_tree(char *s, t_cmd **cmd);

/*
** labeler.c
*/

int				find_label(char *s, t_label **label);
t_label			*new_lable(char *s);
void			add_label(char *s, t_label**label);
int				labeler(char *s, t_label *label);

/*
** labelfind.c
*/

int				labeler2(char *s, t_list *label);

/*
**live.c
*/

void			do_livejmpfork(char *s, t_cmd **cmd, int8_t cmdind);
/*
** lex.c
*/

int				add_cmd_mem(t_cmd **cmd);
int				lexer(char *s, t_strbag2 *all_str);

#endif
