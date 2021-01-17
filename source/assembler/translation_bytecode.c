#include "asm.h"
#include "lexer.h"
#include "logger.h"
#include "asm_errors.h"
#include "ft_printf.h"
#include <stdlib.h>
#include "str.h"
#include "mem.h"
#include "op_struct.h"

//static void check_valid_arg_reg(t_cmd	*cmd, int32_t i)
//{
//	if (cmd->args_types[i] == T_REG	&& (cmd->args_value[i] < 1
//										   && cmd->args_value > REG_NUMBER))
//		log_error(__func__, "%s", ERR_INV_VAl);
//}

void				debugprint(t_list_node *shuffle, size_t i)
{
	int32_t			s1;
	int32_t			s2;
	int32_t			s3;
	int32_t			r1;
	int32_t			r2;
	int32_t			r3;
	char			cd;
	char 			bt;
	char            *mk1;
	char            *mk2;
	char            *mk3;

	cd = ((t_cmd *)(shuffle->data))->code;
	bt = ((t_cmd *)(shuffle->data))->byte_type;

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
	ft_printf("BT:\t%hhx\n", bt);
	ft_printf("FA%llu:\t%i -> %i\t\t",i, s1, r1);
	ft_printf("SA%llu:\t%i -> %i\t\t",i, s2, r2);
	ft_printf("TA%llu:\t%i -> %i\n",i, s3, r3);

	ft_printf("MK1:\t%s\n", mk1);
	ft_printf("MK2:\t%s\n", mk2);
	ft_printf("MK3:\t%s\n", mk3);
}
static void		mark_to_address(t_list_node *shuffle, t_hashmap *mark)
{
	int32_t		iter;
	char 		*buff;
	uint32_t 	val_byte_mark;

	iter = -1;
	while (++iter < 3)
	{
		buff = ((t_cmd*)(shuffle->data))->mark[iter];
		if (!buff)
			continue ;
		val_byte_mark = (unsigned int)(long long)hashmap_get(mark, buff, ft_strlen(buff));
//			step_mark[iter] = val_byte_mark - ((t_cmd *)(shuffle->data))->size_op;
		if(((t_cmd*)(shuffle->data))->mark[iter])
			((t_cmd*)(shuffle->data))->args_value[iter] = val_byte_mark - ((t_cmd *)(shuffle->data))->size_op;
	}
}

static void		arg_types_to_byte(t_list_node *shuffle)
{
	int32_t		iter;

	iter = -1;
	while (++iter < 3)
	{
		if(g_op[((t_cmd*)(shuffle->data))->code].args_types_code)
		{
			if (((t_cmd*)(shuffle->data))->args_types[iter] == T_DIR)
				((t_cmd *)(shuffle->data))->byte_type = ((t_cmd *)(shuffle->data))->byte_type | (ARG1_DIR >> (iter * 2));
			else if (((t_cmd*)(shuffle->data))->args_types[iter] == T_IND)
				((t_cmd *)(shuffle->data))->byte_type = ((t_cmd *)(shuffle->data))->byte_type | (ARG1_IND >> (iter * 2));
			else if (((t_cmd*)(shuffle->data))->args_types[iter] == T_REG)
				((t_cmd *)(shuffle->data))->byte_type = ((t_cmd *)(shuffle->data))->byte_type | (ARG1_REG >> (iter * 2));
		}

	}
}

void				translation_bytecode(t_list *operations, t_hashmap *mark, t_parse *g)
{
	t_list_node		*shuffle;
	t_byte			*str;
	int32_t			step_mark[3];
	register int 	i;
	size_t			j;

	j = 0;
	i = 0;
	ft_bzero(step_mark, sizeof(step_mark));
	str = malloc(g->header->prog_size + 1);
//	size_t					j = 0;
	shuffle = operations->front;
	while (shuffle)
	{
		mark_to_address(shuffle, mark);
		arg_types_to_byte(shuffle);
//
//		while (i < ) //true
//		j = 0;
//		while (j < sizeof(shuffle->data))
//		{
//			str[head_str + j] =
//			j++;
//		}
//		head_str = head_str + j;
		debugprint(shuffle, i);
		i++;
		shuffle = shuffle->next;
	}

}