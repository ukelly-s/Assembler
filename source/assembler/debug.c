//
// Created by Alethia Eclipso on 1/10/21.
//

#include "lexer.h"
void debug_print_lst(t_list *lb)
{
	t_list *tmp;

	tmp = lb;
	printf("%p\n", lb);
	while (tmp)
	{
		printf("L:\t%s\n", ((t_label2 *)tmp->content)->name);
		tmp = tmp->next;
	}
}

void debug_print(t_label *lb)
{
	t_label *tmp;

	tmp = lb;
	printf("%p\n", lb);
	while (tmp)
	{
		printf("L:\t%s\n", tmp->name);
		tmp = tmp->next;
	}
}