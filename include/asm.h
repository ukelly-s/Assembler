/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 05:57:18 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/10 05:57:20 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define SEPARATOR			' '
# define ALT_SEPARATOR		'\t'
# define ALT_COMMENT_CHAR	';'
# define REGISTER_CHAR		'r'

# define ARG_REG 0b01000000
# define ARG_DIR 0b10000000
# define ARG_IND 0b11000000
/*
 # include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include "array_list.h"
# include "conv.h"
# include "hash_map.h"
# include "io_.h"
# include "list.h"
# include "math.h"
# include "mem.h"
# include "str.h"
# include "util.h"
# include "op.h"
# include "op_struct.h"
# include "lexer.h"

 */

#include <mem.h>
# include "list.h"
# include "op.h"
# include "hash_map.h"
# include "lexer.h"
/*
** lexer
*/

typedef enum		e_name_comment_flags
{
	FLAG_DEFAULT,
	FLAG_NAME,
	FLAG_COMMENT
}					t_name_comment_flags;

typedef enum		e_line_type
{
	LINE_UNDEFINED,
	LINE_EMPTY,
	LINE_NAME,
	LINE_COMMENT,
	LINE_OPERATION,
	LINE_MARK
}					t_line_type;

typedef struct		s_parse
{
	int				name;
	int				comment;
	t_header		*header;
	t_byte			*byte_str;
}					t_parse;



void				assembler(char *filename);
void				parse(int fd, t_parse *g, t_list *info_operations,
						  t_hashmap *info_mark);
char				*clear_line(char **str);
int					get_number_operation(const char *str);
void				parse_name(char *str, t_parse *g);
void				parse_comment(char *str, t_parse *g);
t_line_type			mark_operation_type(const char *str);

char			*replace_extension(char *filename, char *file_extension_asm,
								   char *file_extension_disasm);

/*
** libft
*/
char				*ft_strtrim(char const *s);


/*
** parse_operation
*/

void				parse_operation(char *str, t_list *all_op, t_parse *g);
void				parse_mark(char *str, t_hashmap *info_mark, t_parse *g);

/*
** translation to bytecode
*/

void				translation_bytecode(t_list *operations, t_hashmap *mark, t_parse *g);
void 				get_prog_size(t_cmd *cmd);
_Bool	check_name_the_file(char *name_the_file, char *file_extension);

#endif
