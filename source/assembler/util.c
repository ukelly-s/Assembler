#include "asm.h"
#include "asm_errors.h"
#include <string.h> //fixme delete
# include "array_list.h"
# include "str.h"
# include "util.h"
# include "op.h"


t_line_type		mark_operation_type(const char *str)
{
	while (*str != '\0')
	{
		if (*str == SEPARATOR || *str == ALT_SEPARATOR)
			return (LINE_OPERATION);
		if (ft_strchr(LABEL_CHARS, *str) == NULL && *str != LABEL_CHAR)
			ft_kill(ERR_INVALID_STRING, NULL, __func__, __FILE__);
		if (*str == LABEL_CHAR)
			return (LINE_MARK);
		str++;
	}
	ft_kill(ERR_INVALID_STRING, NULL, __func__, __FILE__);
}

int				ft_strnequ(char const *s1, char const *s2, size_t n)//fixme
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (strncmp(s1, s2, n) == 0)//fixme  strncmp -> ft_strncmp
		return (1);
	return (0);
}
