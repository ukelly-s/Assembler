#include "asm.h"
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
# include "ft_printf.h"
# include "op.h"
# include "op_struct.h"
# include "lexer.h"
# include "asm_errors.h"
#include "logger.h"

static int 	get_type_args(char c)
{
	if (c == DIRECT_CHAR)
		return (T_DIR);
	else if (c == REGISTER_CHAR)
		return (T_REG);
	else if (ft_isdigit(c) != 0 || c == '-' || c == LABEL_CHAR)
		return (T_IND);
	else
		ft_kill(ERR_INV_ARG_TYPE, NULL, __func__, __FILE__);
	return (0);
}

static void		check_valid_arg_value(char *str, t_cmd *cmd, int i)
{
	char *tmp;

	tmp = str;
	if (*str == LABEL_CHAR)
		cmd->mark[i] = ft_strdup(++str);
	else
	{
		while (*str != '\0')
		{
			if (ft_isdigit(*str) == 0)
				ft_kill(ERR_INV_CHAR, NULL, __func__, __FILE__);
			str++;
		}
		cmd->args_value[i] = ft_atol(tmp); // todo t_reg check
	}
}

static void	parse_args(char *str, t_cmd	*cmd)
{
	char **args;
	register int 	i;

	i = 0;
	args = ft_strsplit(str, SEPARATOR_CHAR);
	if (args[g_op[cmd->code].args_num] != NULL)
		ft_kill(ERR_LOTS_ARG, NULL, __func__, __FILE__);
	while (args[i] != NULL)
	{
		cmd->args_types[i] = get_type_args(*args[i]);
		if (!(cmd->args_types[i] & g_op[cmd->code].args_types[i]))
			ft_kill(ERR_INV_ARG, NULL, __func__, __FILE__);
		if (cmd->args_types[i] == T_REG && ft_isdigit(args[i][1]) != 0)
			check_valid_arg_value(&args[i][1], cmd, i);
		else if (cmd->args_types[i] == T_IND && (ft_isdigit(*args[i]) != 0
		|| *args[i] == '-' || *args[i] == LABEL_CHAR))
			check_valid_arg_value(&args[i][0], cmd, i);
		else if (cmd->args_types[i] == T_DIR  && (ft_isdigit(args[i][1]) != 0
				|| args[i][1] == '-' || args[i][1] == LABEL_CHAR))
			check_valid_arg_value(&args[i][1], cmd, i);
		else
			ft_kill(ERR_INV_CHAR, NULL, __func__, __FILE__);
		i++;
	}
	ft_free_split(args);
}

void	parse_operation(char *str, t_list *all_str, t_parse *g)
{
	register int		i;
	t_cmd				*list_cmd;

	list_cmd = ft_memalloc(sizeof(t_cmd));
	i = get_number_operation(str);
	ft_printf("%s - %i", str, i);//fixme debug

	list_cmd->code = g_op[i].code;
	parse_args(str + ft_strlen(g_op[i].name) + 1, list_cmd);
	get_prog_size(list_cmd);
	list_cmd->size_op = list_cmd->size_op + g->header->prog_size;
	g->header->prog_size = list_cmd->size_op;
	list_push_back(all_str, list_cmd);
}