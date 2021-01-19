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

//fixme
static void		get_to_4byte(t_byte	*str, int32_t args_value)
{
	t_code4b 		unite;
	unite.digit = args_value;
	str[0] = unite.letter[3];
	str[1] = unite.letter[2];
	str[2] = unite.letter[1];
	str[3] = unite.letter[0];
}

static void		get_to_2byte(t_byte	*str, int32_t args_value)
{
	t_code4b 		unite;
	unite.digit = args_value;
	str[0] = unite.letter[1];
	str[1] = unite.letter[0];
}

static uint8_t arg_types_to_byte(const uint8_t *args_types, uint8_t	code)
{
	int32_t		iter;
	uint8_t 	byte_type;

	byte_type = 0;
	iter = -1;
	while (++iter < 3)
	{
		if(g_op[code].args_types_code)
		{
			if (args_types[iter] == T_DIR)
				byte_type |= (ARG_DIR >> (iter * 2));
			else if (args_types[iter] == T_IND)
				byte_type |= (ARG_IND >> (iter * 2));
			else if (args_types[iter] == T_REG)
				byte_type |= (ARG_REG >> (iter * 2));
		}
	}
	return (byte_type);
}

static void		op_to_bytecode(t_cmd *cmd, t_parse *g)
{
	static int			i = -1;
	register int		j;

	j = 0;
	g->byte_str[++i] = (uint8_t)cmd->code;
	if (g_op[cmd->code].args_types_code)
		g->byte_str[++i] = arg_types_to_byte(cmd->args_types, cmd->code);
	while (cmd->args_types[j] && j < 3)
	{
		if (cmd->args_types[j] == T_REG)
			g->byte_str[++i] = (uint8_t)cmd->args_value[j];
		else if ((cmd->args_types[j] == T_DIR
				&& g_op[cmd->code].t_dir_size == 2)
				|| (cmd->args_types[j] == T_IND))
		{
			get_to_2byte(&g->byte_str[++i], cmd->args_value[j]);
			++i;
		}
		else
		{
			get_to_4byte(&g->byte_str[++i], cmd->args_value[j]);
			i += 3;
		}
		j++;
	}
}


void		translation_bytecode(t_list *operations, t_hashmap *mark, t_parse *g)
{
	t_list_node		*info_op;

	g->byte_str = ft_memalloc(g->header->prog_size );
	info_op = operations->front;
	while (info_op)
	{
		mark_to_address((t_cmd*)(info_op->data), mark);
	//	arg_types_to_byte((t_cmd*)(info_op->data));
		op_to_bytecode((t_cmd*)(info_op->data), g);


		info_op = info_op->next;
	}
    g->header->prog_size = rev_bytes(g->header->prog_size);
}