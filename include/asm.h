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

# define ALT_COMMENT_CHAR		';'

typedef enum			e_line_type
{
	LINE_NAME,
	LINE_COMMENT,
	LINE_OPERATION,
	LINE_ARGUMENT
}						t_line_type;

typedef struct			s_parser
{
	int					fd;
	unsigned 			line;
	char				*name;
	char				*comment;
	char				*code;
}						t_parser;

char	*ft_strtrim(char const *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_strrev(register char *begin);
void	*assembler(char *filename);
void	*disassembler(char *filename);
int 	get_line(int fd, char *line);
void	parse(int fd);

#endif
