//
// Created by Alethia Eclipso on 1/10/21.
//

#include "asm.h"
#include "lexer.h"

int find_label(char *s, t_label **label)
{
	t_label     *tmp;
	int         found;

	found = NOTFOUND;
	if (!(*label))
		return (NOTFOUND);
	if (!((*label)->next))
		return (ft_strequ(s, (*label)->name));
	else
		tmp = *label;
	while (tmp)
	{
		if (ft_strequ(s, tmp->name))
			found = FOUND;
		tmp = tmp->next;
	}
	printf("TTTTT\n"); //debug
	return (found);
}

t_label *new_lable(char *s)
{
	t_label *new;

	if(!(new = (t_label *)malloc(sizeof(t_label))))
		return (NULL);
	new->next = NULL;
	new->name = ft_strdup(s);
	return (new);
}

void add_label(char *s, t_label **label)
{
	t_label *tmp;

	tmp = *label;
	if (label)
	{
		if (*label)
		{
			while ((*label)->next)
				(*label) = (*label)->next;
			(*label)->next = new_lable(s);
		}
	}
	*label = tmp;
}

int labeler(char *s, t_label *label)
{
	if (!(find_label(s, label)))
		add_label(s, label);
	return (0);
}