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
# include "lexer.h"

# define SEPARATOR	' '
# define ALT_SEPARATOR		'\t'
# define ALT_COMMENT_CHAR	';'

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
}					t_parse;

void				*ft_strrev(register char *begin);
void				*assembler(char *filename);
void				*disassembler(char *filename);
int					get_line(int fd, char **line);
void				parse(int fd, t_parse *g, t_strbag2 *all_str);
char				*clear_line(char **str);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					number_operation(const char *str);
void				parse_name(char *str, t_parse *g);
void				parse_comment(char *str, t_parse *g);
t_line_type			mark_operation_type(const char *str);
/*
** libft
*/
char				*ft_strtrim(char const *s);

/*
** parse_operation
*/

void				parse_operation(char *str, t_strbag2 *all_str);

#endif
