#include "lexer.h"

int whatistype(char *s)
{
	size_t  len;

	len = ft_strlen_prot(s);
	if (s[len - 1] == ':')
		return (LABEL);
	return (CMD);
}

void    set_addr_label(t_strbag *bag)
{
	bag->label->address = bag->cmd->n_cmd;
}

int     add_cmd_mem(t_cmd **cmd) //est v command
{
	t_cmd       *tmp;

	tmp = *cmd;
	if(!(*cmd))
	{
		if (!(*cmd = ft_memalloc(sizeof(t_cmd))))
			return (0);
	}
	else
	{
		while (tmp)
			tmp = tmp->next;
		if (!(tmp = (t_cmd *)ft_memalloc(sizeof(t_cmd))))
			return (0);
	}
	return (1);
}
//TODO: глобальная структура, которая подаётся сюда, чтобы чистить из 1 места.

int lexer(char *s)
{
	t_strbag        all_str;
	int             type;
	static int      prev_type;
	static size_t   nbr_cmd;

	//функция калькулятор для расчёта относительной позиции метки
	type = whatistype(s);
	ft_bzero(&all_str, sizeof(all_str));
	if (type == LABEL)
	{
		labeler(s, &all_str.label);
		prev_type = LABEL;
		debug_print(all_str.label);
	}
	else if (type == CMD)
	{
		if (!(add_cmd_mem(&all_str.cmd)))
			exit(0); //malloc
		find_cmd_tree(s, &all_str.cmd);
		all_str.cmd->n_cmd = nbr_cmd;      //not work
		if (prev_type == LABEL)
			set_addr_label(&all_str);
		prev_type = CMD;
		nbr_cmd++;
		printf("CMD:\t%zu\n", nbr_cmd); //debug
	}
	return 0;
}



