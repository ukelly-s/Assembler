#include "asm.h"
#include "lexer.h"
#include "ft_printf.h"
#include <stdlib.h>
#include "str.h"
void				translation_bytecode(t_list *operations, t_hashmap *mark, t_parse *g)
{
	t_list_node 			*shuffle;
	uint8_t					*str;
	uint32_t                iter;
	uint8_t					*step;
	unsigned int				calc;


	str = malloc(sizeof(t_cmd));
//	str = (uint8_t *)realloc(str, sizeof(t_cmd));
	iter = 0;

	char            s1;
	char            s2;
	char            s3;
	char            r1;
	char            r2;
	char            r3;
	char            cd;
	char            *mk1;
	char            *mk2;
	char            *mk3;
	size_t          i = 0;

	shuffle = operations->front;
	while (shuffle)
	{
		while (iter < sizeof(t_cmd))
		{
			str = (uint8_t *)realloc(str, sizeof(t_cmd) * iter);
			str[iter] = ((t_cmd *)(shuffle->data))->code;
			//todo in [i] elem is mark
			calc = (unsigned int)(long long)hashmap_get(mark, ((t_cmd*)(shuffle->data))->mark[2], ft_strlen(((t_cmd*)(shuffle->data))->mark[2]));
					//(unsigned int)(long long)hashmap_get(mark, (void*)((t_cmd *)(shuffle->data))->mark[2], ft_strlen(((t_cmd *)(shuffle->data))->mark[2]));


			iter++;
		}

		cd = ((t_cmd *)(shuffle->data))->code;

		s1 = ((t_cmd *)(shuffle->data))->args_value[0];
		s2 = ((t_cmd *)(shuffle->data))->args_value[1];
		s3 = ((t_cmd *)(shuffle->data))->args_value[2];

		r1 = ((t_cmd *)(shuffle->data))->args_types[0];
		r2 = ((t_cmd *)(shuffle->data))->args_types[1];
		r3 = ((t_cmd *)(shuffle->data))->args_types[2];

		mk1 = ((t_cmd *)(shuffle->data))->mark[0];
		mk2 = ((t_cmd *)(shuffle->data))->mark[1];
		mk3 = ((t_cmd *)(shuffle->data))->mark[2];

		ft_printf("CD:\t%hu\n", cd);
		ft_printf("FA%llu:\t%hu -> %hu\t\t",i, s1, r1);
		ft_printf("SA%llu:\t%hu -> %hu\t\t",i, s2, r2);
		ft_printf("TA%llu:\t%hu -> %hu\n",i, s3, r3);

		ft_printf("MK1:\t%s\n", mk1);
		ft_printf("MK2:\t%s\n", mk2);
		ft_printf("MK3:\t%s\n", mk3);
		i++;
		shuffle = shuffle->next;
	}

}
