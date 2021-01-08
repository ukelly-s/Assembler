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