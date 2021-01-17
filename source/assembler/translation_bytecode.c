#include "asm.h"
#include "lexer.h"
#include "logger.h"
#include "asm_errors.h"
#include "ft_printf.h"
#include <stdlib.h>
#include "str.h"
#include "mem.h"
#include "op_struct.h"
# include	"list.h"

static void	mark_to_address(t_cmd *cmd, t_hashmap *mark)
{
	int32_t		iter;
	char 		*buff;
	uint32_t 	val_byte_mark;

	iter = -1;
	while (++iter < 3)
	{
		buff = cmd->mark[iter];
		if (!buff)
			continue ;
		val_byte_mark = (unsigned int)(long long)hashmap_get(mark,
													   buff, ft_strlen(buff));
		if(cmd->mark[iter])
			cmd->args_value[iter] = val_byte_mark -	cmd->size_op;
	}
}

static void	arg_types_to_byte(t_cmd *cmd)
{
	int32_t		iter;

	iter = -1;
	while (++iter < 3)
	{
		if(g_op[cmd->code].args_types_code)
		{
			if (cmd->args_types[iter] == T_DIR)
				cmd->byte_type |= (ARG_DIR >> (iter * 2));
			else if (cmd->args_types[iter] == T_IND)
				cmd->byte_type |= (ARG_IND >> (iter * 2));
			else if (cmd->args_types[iter] == T_REG)
				cmd->byte_type |= (ARG_REG >> (iter * 2));
		}

	}
}

static void	op_bytecode(t_cmd *cmd, t_parse *g)
{

}

//fixme
void		int_to_byte(char **str, t_cmd *cmd)
{
	t_codeint 		unite;

	str[0] = unite.letter[0];
	str[1] = unite.letter[1];
	str[2] = unite.letter[2];
	str[3] = unite.letter[3];
}

void		translation_bytecode(t_list *operations, t_hashmap *mark, t_parse *g)
{
	t_list_node		*info_op;

	g->byte_str = ft_memalloc(g->header->prog_size + 1);
	info_op = operations->front;
	while (info_op)
	{
		mark_to_address((t_cmd*)(info_op->data), mark);
		arg_types_to_byte((t_cmd*)(info_op->data));
		op_bytecode((t_cmd*)(info_op->data), g);


		info_op = info_op->next;
	}

}