int is_label(char *s)
{
	size_t len = ft_strlen_prot(s);

	if (s[len - 1] == ':')
		return (1);
	return (0);
}

t_label *new_label(void)
{
	t_label *tmp;

	if (!(tmp = (t_label *)malloc(sizeof(t_label))))
		return (NULL);
	return tmp;
}

int create_label(t_label *labels, char *s)
{
	t_label     *tmp;
	t_label     *start;
	size_t      i;

	i = 0;

	if (!(tmp = new_label()))
		return (0);
	if (!(labels))
		tmp->id = 0;
	else
	{
		start = labels;
		while (labels->next)
		{
			i++;
			labels=labels->next;
		}
	}
	tmp->id = i + 1;
	tmp->name = ft_strdup_prot(s);
	tmp->next = NULL;
	if (labels && labels->next)
		labels->next->next = tmp;
	else
		labels = tmp;
	return (1);
}
