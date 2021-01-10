 #ifndef ASSEMBLER_LEXER_H
#define ASSEMBLER_LEXER_H

#include <stdint.h>
#include <stdio.h> // debug
#include <stdlib.h>
#include <limits.h>

 typedef struct	s_label{
	 char		    *name;
	 int32_t		id;
	 int32_t		address;   //байт сначала файла
	 int32_t        n_cmd;     //номер строки прише
	 struct s_label *next;
 }				t_label;

 typedef struct s_cmd{
	 char             *cmd;           //namecmd
	 int32_t          n_cmd;         //id
	 int32_t		     id;            //zapasnoi

	 int8_t           name_code;
	 int32_t          args_type[3];  //тип аругмента, если 0 тогда нет аргумента соотв. REG_CODE,DIR_CODE,IND_CODE
	 int32_t          args[3];       //сами аргументы
	 int8_t           args_types_code; //тип кодов аргументов
	 int32_t          args_weight[3]; //вес аргументов, если 0, то веса нет

	 struct s_cmd    *next;
 }               t_cmd;

 typedef struct	s_strbag{
	 t_label		*label;
	 t_cmd          *cmd;
 }				t_strbag;


 //lib.c
 void				ft_bzero(void *s, size_t n);
 int				ft_strequ(char const *s1, char const *s2);
 void	            *ft_memalloc(size_t size);
 size_t				ft_strlen_prot(const char *str);
 char				*ft_strdup_prot(const char *s);
 long long	        ft_atol(const char *str);

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

 //live.c
 void do_livejmpfork(char *s, t_cmd **cmd, int8_t cmdind);

 //lex.c
 int     add_cmd_mem(t_cmd **cmd);
 int lexer(char *s);

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

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
#endif
