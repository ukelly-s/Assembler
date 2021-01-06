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

# define ALT_COMMENT_CHAR	';'

//char 	*name;
//char 	*comment;
//int		code_size;
//char 	*g_clear_line;

typedef enum			e_line_type
{
	LINE_UNDEFINED,
	LINE_NAME,
	LINE_COMMENT,
	LINE_OPERATION,
	LINE_ARGUMENT
}						t_line_type;

void					*ft_strrev(register char *begin);
void					*assembler(char *filename);
void					*disassembler(char *filename);
int						get_line(int fd, char **line);
void					parse(int fd);
char					*array_words_to_string(char **str, int len_str, int count_words);
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
