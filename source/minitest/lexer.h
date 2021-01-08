 #ifndef ASSEMBLER_LEXER_H
#define ASSEMBLER_LEXER_H

#include <stdint.h>
#include "lexer.h"
//#include "libft.h"
#include <stdio.h> // debug
#include <stdlib.h>

 typedef struct	s_label{
	 char		    *name;
	 int32_t		id;
	 int32_t		address;
	 int32_t        n_cmd;
	 struct s_label *next;
 }				t_label;

 typedef struct s_cmd{
	 char            *cmd;
	 int32_t          args_cnt;
	 int32_t          n_cmd;
	 int32_t          args_type[4];
	 int32_t          args[4];
	 struct s_cmd    *next;
 }               t_cmd;

 typedef struct	s_strbag{
	 t_label		*label;
	 t_cmd       *cmd;
 }				t_strbag;


 //lib.c
 void				ft_bzero(void *s, size_t n);
 int					ft_strequ(char const *s1, char const *s2);
 void	            *ft_memalloc(size_t size);
 size_t				ft_strlen_prot(const char *str);
 char				*ft_strdup_prot(const char *s);

//find_cmd.c

 void    write_cmd_fork(char *s, t_cmd **cmd_fork);
 int     cmd_l(char *s, t_cmd **cmd);
 int     cmd_s(char *s, t_cmd **cmd);
 int     cmd_a(char *s, t_cmd **cmd);
 int		find_cmd_tree(char *s, t_cmd **cmd);

//labeler.c
 int find_label(char *s, t_label **label);
 t_label *new_lable(char *s);
 void add_label(char *s, t_label **label);
 int labeler(char *s, t_label **label);

 //debug.c
 void debug_print(t_label *lb);

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

# define T_DIR 0x100
# define T_IND 0x200
# define T_REG 0x400
# define T_ZER 0x800

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
#endif
