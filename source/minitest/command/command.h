#include <stdio.h>
#include <stdint.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

typedef struct	s_label{
	char		    *name;
	int32_t		    id;
	int32_t		    address;   //байт сначала файла
	int32_t        n_cmd;     //номер строки прише
	struct s_label *next;
}				t_label;

typedef struct s_cmd{
	char             *cmd;           //namecmd
	int32_t          n_cmd;         //id
	int32_t		     id;            //zapasnoi

	int32_t          args_cnt;      //число аргументов
	int8_t           args_types_code; //тип кодов аргументов
	int32_t          args_type[4];  //тип аругмента, если 0 тогда нет аргумента соотв. REG_CODE,DIR_CODE,IND_CODE
	int32_t          args[4];       //сами аргументы
	struct s_cmd    *next;
}               t_cmd;

typedef struct	s_strbag{
	t_label		*label;
	t_cmd          *cmd;
}				t_strbag;

//utils.c
char	            *ft_strdup_prot(const char *s);
int                 add_cmd_mem(t_cmd **cmd);
void	            *ft_memalloc(size_t size);

//live.c
void do_livejmpfork(char *s, t_cmd **cmd, int cmdind);
