#include "asm.h"

void	*ft_strrev(register char *begin)
{
	register char		tmp;
	register char		*end;

	end = begin;
	while (*end != '\0')
		end++;
	end--;
	while (end > begin)
	{
		tmp = *end;
		*end-- = *begin;
		*begin++ = tmp;
	}
}
