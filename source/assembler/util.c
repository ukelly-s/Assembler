#include "asm.h"
#include "asm_errors.h"
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
	return (LINE_UNDEFINED);
}

uint32_t		rev_bytes(uint32_t define)
{
	uint32_t	rev_dig;
	uint8_t		*col;
	uint8_t		*rev_col;

	col = (uint8_t *)&define;
	rev_col = (uint8_t *)&rev_dig;
	rev_col[0] = col[3];
	rev_col[1] = col[2];
	rev_col[2] = col[1];
	rev_col[3] = col[0];
	return (rev_dig);
}