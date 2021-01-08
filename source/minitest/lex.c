#include "lexer.h"
//#include "libft.h"
#include <stdio.h> // debug
#include <stdlib.h>

///lft///
int		            find_start_cmd(char *s)
{
		if (s[0] == L || s[0] == S
		|| s[0] == A || s[0] == O
		|| s[0] == X || s[0] == Z
		|| s[0] == F)
			return (1);
		else
			return (0);
}

void				ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	if (!n)
		return ;
	i = 0;
	arr = (unsigned char *)s;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
}

int					ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*arr;
	unsigned char	*arr2;
	size_t			i;

	if (!s1 || !s2)
		return (0);
	arr = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	i = 0;
	while ((arr[i] == arr2[i]) && arr[i] && arr2[i])
		i++;
	if (arr[i] == arr2[i])
		return (1);
	else
		return (0);
}

void	            *ft_memalloc(size_t size)
{
	unsigned char	*arr;
	size_t			i;

	if (size == 0)
		return (NULL);
	i = 0;
	if (!(arr = (unsigned char*)malloc(size)))
		return (NULL);
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void*)arr);
}

size_t				ft_strlen_prot(const char *str)
{
	size_t			i;
	unsigned char	*arr;

	if (str == NULL)
		return (0);
	i = 0;
	arr = (unsigned char*)str;
	while (arr[i] != '\0')
	{
		i++;
	}
	return (i);
}

char				*ft_strdup_prot(const char *s)
{
	size_t			i;
	char			*arr;

	i = ft_strlen_prot(s);
	if (s == NULL)
		return (NULL);
	if (!(arr = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
///lft///

///cmd///

void    write_cmd_fork(char *s, t_cmd **cmd_fork)
{
	//сюда чтобы поступало уже замалочено
	(*cmd_fork)->cmd = ft_strdup_prot(s);
	(*cmd_fork)->args_type[0] = T_DIR;
	printf("%i\n", T_REG);
	return;
}

int     cmd_l(char *s, t_cmd **cmd)
{
	if (s[1] == I)
	{
		if (s[2] == V && s[3] == E)
			printf("this is live\n");
	}
	else if (s[1] == D)
	{
		if (s[2] != I)
			printf("this is ld\n");
		else if (s[2] == I)
			printf("this is ldi\n");
	}
	else if (s[1] == L)
	{
		if (s[2] == D)
		{
			if (s[3] != I)
				printf("this is lld\n");
			else if (s[3] == I)
				printf("this is lldi\n");
		}
	}
	else if (s[1] == F)
	{
		if (s[2] == O && s[3] == R && s[4] == K)
			printf("this is lfork\n");
	}
	return (0);
}

int     cmd_s(char *s, t_cmd **cmd)
{
	if (s[1] == T)
	{
		if (s[2] != I)
			printf("this is st\n");
		else if (s[2] == I)
			printf("this is sti\n");
	}
	else if (s[1] == U)
	{
		if (s[2] == B)
			printf("this is sub\n");
		else if(s[2] != B)
			printf("NOT SUB..");
	}
	return (0);
}

int     cmd_a(char *s, t_cmd **cmd)
{
	if (s[1] == D && s[2] == D)
		printf("this is add\n");
	else if (s[1] == N && s[2] == D)
		printf("this is and\n");
	else if (s[1] == F && s[2] == F)
		printf("this is aff\n");
	return (0);
}

int		find_cmd_tree(char *s, t_cmd **cmd)
{
	if (s[0] == L)
		cmd_l(s, cmd);
	else if (s[0] == S)
		cmd_s(s, cmd);
	else if (s[0] == A)
		cmd_a(s, cmd);
	else if (s[0] == O && s[1] == R)
		printf("this is or\n");
	else if (s[0] == X && s[1] == O && s[2] == R)
		printf("this is xor\n");
	else if (s[0] == Z && s[1] == J && s[2] == M && s[3] == P)
		printf("this is zjmp\n");
	else if (s[0] == F && s[1] == O && s[2] == R && s[3] == K)
		write_cmd_fork(s, cmd);
	else
		printf("not founded\n");
	return 0;
}

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
	new->name = ft_strdup_prot(s);
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

int labeler(char *s, t_label **label)
{
	if (!(find_label(s, label)))
		add_label(s, label);
	return (0);
}

int whatistype(char *s)
{
	size_t  len;

	len = ft_strlen_prot(s);
	if (s[len - 1] == ':')
		return (LABEL);
	return (CMD);
}

void debug_print(t_label *lb)
{
	t_label *tmp;

	tmp = lb;
	while (tmp)
	{
		printf("L:\t%s\n", tmp->name);
		tmp = tmp->next;
	}
}

void    set_addr_label(t_strbag *bag)
{
	bag->label->address = bag->cmd->n_cmd;
}

int     add_cmd_mem(t_cmd **cmd)
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
		{
			tmp = tmp->next;
		}
		if (!(tmp = ft_memalloc(sizeof(t_cmd))))
			return (0);
	}
	return (1);
}

int lexer(char *s)
{
	t_strbag        all_str;
	int             type;
	static int      prev_type;

	type = whatistype(s);
	ft_bzero(&all_str, sizeof(all_str));
	//debug
		all_str.label = (t_label*)malloc(sizeof(t_label));
		all_str.label->name = (char *)malloc(sizeof(char) * 6);
		all_str.label->name = "loop:";
		all_str.label->next = NULL;

		all_str.label->next = (t_label*)malloc(sizeof(t_label));
		all_str.label->next->name = (char *)malloc(sizeof(char) * 6);
		all_str.label->next->name ="zzz:";
		all_str.label->next->next = NULL;

		all_str.label->next->next = (t_label*)malloc(sizeof(t_label));
		all_str.label->next->next->name = (char *)malloc(sizeof(char) * 6);
		all_str.label->next->next->name = "abc:";
		all_str.label->next->next->next = NULL;
	//end debug
	if (type == LABEL)
	{
		labeler(s, &all_str.label);
		prev_type = LABEL;
		debug_print(all_str.label);
	}
	else if (type == CMD)
	{
		add_cmd_mem(&all_str.cmd);
		find_cmd_tree(s, &all_str.cmd);
		if (prev_type == LABEL)
			set_addr_label(&all_str);
		prev_type = CMD;
		printf("CMD\n"); //debug
	}
	return 0;
}


int main()
{
	printf("\tTEST_1\n");
	char *s1 = "fork\t%:b1";
	lexer(s1);
}