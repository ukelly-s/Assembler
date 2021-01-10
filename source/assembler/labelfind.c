//
// Created by Alethia Eclipso on 1/10/21.
//
#include "lexer.h"
#include "asm_errors.h"

/*
 static void    print_input(t_list *input)
{
   register t_list_node   *node;
   if (input->size == 0)
      return ;
   node = input->front;
   while (node != NULL)
   {
      ft_putstr(node->data);
      ft_putstr("\n");
      node = node->next;
   }
   ft_putstr("\n");
}
 * */
int find_label2(char *s, t_list *label)
{
//	t_list  *shuffle;
//	int     found;
//	register t_list_node   *node;
//
//	found = NOTFOUND;
//	if (!label)
//		return (NOTFOUND);
//	node = label->front;
//	if(!(node->next))
//		return (ft_strequ(s, ((t_label2*)node->data)->name));
//	else
//		shuffle = node;
//	while (shuffle)
//	{
//		if (ft_strequ(s, ((t_label2*)node->data)->name))
//			found = FOUND;
//		shuffle = shuffle->next;
//	}
//	return (found);
}

t_label2 *new_lable2(char *s)
{
	t_label2 *new;

	if (!(new = (t_label2*)malloc(sizeof(t_label2))))
		ft_kill(ERR_INV_LINE, NULL, __func__, __FILE__);
	new->name = ft_strdup(s);
	return (new);
}

void    add_label2(char *s, t_list *label)
{
//	t_list  *new;
//	t_label2 content;
//
//	t_list *shuffle;
//	shuffle = *label;
//	content.name = ft_strdup(s);
//	content.id = 500;
//	new = ft_lstnew(&content);
//	if (!(*label))
//	{
//		*label =  new;
//		(*label)->next = NULL;
//	}
//	ft_lstadd_back(label, new);
//	while (shuffle)
//	{
//		printf("%s\n", ((t_label2 *)(shuffle->content))->name);
//		shuffle = shuffle->next;
//	}
}

int labeler2(char *s, t_list *label)
{
	if (!(find_label2(s, label)))
		add_label2(s, label);
//	*label = ft_lstnew("govno");
	return (0);
}