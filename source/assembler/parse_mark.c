#include "ft_printf.h"
#include "asm.h"
# include "hash_map.h"
# include "list.h"
# include "str.h"

void				parse_mark(char *str, t_hashmap *info_mark, t_parse *g)
{
	if (hashmap_get(info_mark, str, ft_strlen(str) - 1) != NULL)
		return;
	ft_printf(str);//fixme debug from logger
	hashmap_put(info_mark, str, ft_strlen(str) - 1, (void*)(long long)g->header->prog_size);//fixed обратно: (unsigned int)(long long)
}