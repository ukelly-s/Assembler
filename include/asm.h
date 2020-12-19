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

char 	*name;
char 	*comment;
int		code_size;

typedef enum			e_line_type
{
	LINE_NAME,
	LINE_COMMENT,
	LINE_OPERATION,
	LINE_ARGUMENT
}						t_line_type;

void					*ft_strrev(register char *begin);
void					*assembler(char *filename);
void					*disassembler(char *filename);
int						get_line(int fd, char *line);
void					parse(int fd);

#endif
