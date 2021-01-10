//
// Created by Alethia Eclipso on 1/10/21.
//
#include "asm.h"
#include "lexer.h"

void do_livejmpfork(char *s, t_cmd **cmd, int8_t cmdind)
{
	int i = 0;

	while ((*cmd)->next)
		*cmd = (*cmd)->next;
	(*cmd)->cmd = ft_strdup(s);
	(*cmd)->args_cnt = 1;
	(*cmd)->args_types_code = 0;
	(*cmd)->args_type[0] = DIR_CODE;
	(*cmd)->name_code = cmdind;
	if (cmdind == FORK || cmdind == LFORK || cmdind == ZJMP)
		(*cmd)->args_weight[0] = 2;
	else if (cmdind == LIVE)
	{
		(*cmd)->args_weight[0] = 4;
	}
	printf("%s : %i\n", s, (*cmd)->n_cmd);
	while (s[i] != '%')
		i++;
	if (ft_isdigit(s[i + 1]))
		(*cmd)->args[0] = ft_atol(&s[i + 1]);
	else if (s[i + 1] == ':')
		printf("LAB\n");
}