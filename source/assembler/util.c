#include "asm.h"
#include "asm_errors.h"
# include "array_list.h"
# include "str.h"
# include "util.h"
# include "op.h"
# include "op_struct.h"

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

void		get_prog_size(t_cmd *cmd)
{
	register int 	i;

	i = 0;

	cmd->size_op++;
	if (g_op[cmd->code].args_types_code == true)
		cmd->size_op++;
	while (i < g_op[cmd->code].args_num)
	{
		if ((cmd->args_types[i] & g_op[cmd->code].args_types[i]))
		{
			if (cmd->args_types[i] == T_REG)
				cmd->size_op++;
			else if (cmd->args_types[i] == T_IND)
				cmd->size_op += 2;
			else
				cmd->size_op += g_op[cmd->code].t_dir_size;
		}
		i++;
	}

}