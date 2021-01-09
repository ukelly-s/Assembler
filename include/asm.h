#ifndef ASM_H
#define ASM_H

# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include "array_list.h"
# include "conv.h"
# include "hash_map.h"
# include "io.h"
# include "list.h"
# include "math.h"
# include "mem.h"
# include "str.h"
# include "util.h"
# include "op.h"
# include "op_struct.h"

# define SEPARATOR			' '
# define ALT_SEPARATOR		'\t'
# define ALT_COMMENT_CHAR	';'
/**
 * lexer
 **/
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

typedef enum			e_name_comment_flags
{
	FLAG_DEFAULT,
	FLAG_NAME,
	FLAG_COMMENT
}						t_name_comment_flags;

typedef enum			e_line_type
{
	LINE_UNDEFINED,
	LINE_EMPTY,
	LINE_NAME,
	LINE_COMMENT,
	LINE_OPERATION,
	LINE_MARK
}						t_line_type;

typedef struct			s_parse
{
	int 			name;
	int				comment;
}						t_parse;

void					*ft_strrev(register char *begin);
void					*assembler(char *filename);
void					*disassembler(char *filename);
int						get_line(int fd, char **line);

void					parse(int fd, t_parse *g);
char					*clear_line(char **str);
int						ft_strnequ(char const *s1, char const *s2, size_t n);

/**
 * libft
 **/
char			*ft_strtrim(char const *s);


/*
 * cmd
 */
int     find_cmd(char *s);

#endif
