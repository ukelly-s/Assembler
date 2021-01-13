#include "asm.h"
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

static int 	get_type_args(char c)
{
	if (c == DIRECT_CHAR)
		return (T_DIR);
	else if (c == REGISTER_CHAR)
		return (T_REG);
	else if (ft_isdigit(c) != 0 || c == '-' || c == LABEL_CHAR)
		return (T_IND);
	else
		ft_kill("Некорректный тип аргумента" , NULL, __func__, __FILE__);
	return (0);
}

static void	parse_args(char *str, t_cmd	*cmd)
//todo проверить аргументы, если не метка то в аргументе то запятой может быть
//todo r, % , -, числа, а также проверить чтобы всего вместе в одном арг этого тоже не было
{
	char **args;
	register int 	i;
	char *check_mark;

	i = 0;
	args = ft_strsplit(str, SEPARATOR_CHAR);
	if (args[g_op[cmd->code].args_num] != NULL)
		ft_kill("Много аргументов", NULL, __func__, __FILE__);
	while (args[i] != NULL)
	{
		cmd->args_types[i] = get_type_args(*args[i]);
		if (!(cmd->args_types[i] & g_op[cmd->code].args_types[i]))
			ft_kill("Некорректный аргумент", NULL, __func__, __FILE__);
		if ((check_mark = ft_strchr(args[i], LABEL_CHAR)) != NULL)
			cmd->mark[i] = ft_strdup(++check_mark);
		else if (cmd->args_types[i] == T_IND)
			cmd->args_value[i] = ft_atol(args[i]);//todo указатель на начало числа
		else if (cmd->args_types[i] == T_DIR || cmd->args_types[i] == T_REG)
			cmd->args_value[i] = ft_atol(++(args[i]));
		i++;
	}
}

void	parse_operation(char *str, t_list *all_str, t_parse *g)
{
	register int		i;
	t_cmd				*list_cmd;

	list_cmd = ft_memalloc(sizeof(t_cmd));
	ft_putstr(str);//fixme delete
	i = get_number_operation(str);
	list_cmd->code = g_op[i].code;
	parse_args(str + ft_strlen(g_op[i].name), list_cmd);
//todo при переводе в байт код смотрим args_value[i] == 0 значит mark[i] != 0 и наоборот
//todo лично для Пашти разъяснение СНАЧАЛА СМОТРИМ НА МЕТКИ
//todo но как по мне в лююбом случае смотри и туда
}