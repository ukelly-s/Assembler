#include "io_.h"
#include "asm.h"
#include "asm_errors.h"
# include "list.h"
# include "mem.h"
# include "str.h"
# include "util.h"
# include "op.h"

static void		check_excess_information(char *str)
{
	char *buff;

	buff = ft_strchr(ft_strchr(str, '"') + 1, '"') + 1;
	while (*buff != '\0')
	{
		if (*buff == COMMENT_CHAR || *buff == ALT_COMMENT_CHAR)
		{
			ft_bzero(buff, ft_strlen(buff));
			break;
		}
		if (*buff != SEPARATOR && *buff != ALT_SEPARATOR)
			ft_kill(ERR_NAME_COMMENT, NULL, __func__, __FILE__);
		buff++;
	}
}

void	parse_comment(char *str, t_parse *g)
{
	register int 	len;
	register int	i;
	char 			*buff;

	i = 0;
	check_excess_information(str);
	buff = ft_strchr(str, '"') + 1;
	if ((len = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '"'))) > PROG_NAME_LENGTH )//TODO fixme
		ft_kill(ERR_COM_LEN, NULL, __func__, __FILE__);
	while (i < len)
		g->header->comment[i++] = *buff++;
}

void	parse_name(char *str, t_parse *g)
{
	register int 	len;
	register int	i;
	char 			*buff;

	i = 0;
	check_excess_information(str);
	buff = ft_strchr(str, '"') + 1;
	if ((len = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '"'))) > PROG_NAME_LENGTH )//TODO fixme
		ft_kill(ERR_PROG_NAME_LEN, NULL, __func__, __FILE__);
	while (i < len)
		g->header->prog_name[i++] = *buff++;
}
