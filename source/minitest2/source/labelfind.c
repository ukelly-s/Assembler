//
// Created by Alethia Eclipso on 1/10/21.
//
#include "lexer.h"

void error_malloc(void)
{
	ft_printf("ERROR_ALLOCATION IN LAB\n");
	exit(1);
}


int find_label2(char *s, t_list **label)
{
	t_list  *shuffle;
	int     found;

	found = NOTFOUND;
	if (!(*label))
		return (NOTFOUND);
	if(!((*label)->next))
		return (ft_strequ(s, ((t_label2*)(*label)->content)->name));
	else
		shuffle = *label;
	while (shuffle)
	{
		if (ft_strequ(s, ((t_label2*)(*label)->content)->name))
			found = FOUND;
		shuffle=shuffle->next;
	}
	return (found);
}

t_label2 *new_lable2(char *s)
{
	t_label2 *new;

	if (!(new = (t_label2*)malloc(sizeof(t_label2))))
		error_malloc();
	new->name = ft_strdup(s);
	return (new);
}

void    add_label2(char *s, t_list **label)
{
	t_list  *new;
	t_label2 content;

	t_list *shuffle;
	shuffle = *label;
	content.name = ft_strdup(s);
	content.id = 500;
	new = ft_lstnew(&content);
	if (!(*label))
	{
		*label =  new;
		(*label)->next = NULL;
	}
	ft_lstadd_back(label, new);
	while (shuffle)
	{
		printf("%s\n", ((t_label2 *)(shuffle->content))->name);
		shuffle = shuffle->next;
	}
}

int labeler2(char *s, t_list **label)
{
	if (!(find_label2(s, label)))
		add_label2(s, label);
//	*label = ft_lstnew("govno");
	return (0);
}