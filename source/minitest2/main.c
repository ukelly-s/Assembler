#include "lexer.h"
#include "libft.h"
int main()
{
//	printf("\tTEST_1\n");
//	char *s1 = "fork\t%:b1";
//	lexer(s1);
//	char **s;
//
//
//
//	s[0] = "live%742";
//	s[1] = "ld%0,r3";
//	s[2] = "str5,r2";
//	s[3] = "addr10,r10,r10";
//	s[4] = "subr2,r4,r2";
//	s[5] = "andr6,%2147483648,r8";
//	s[6] = "orr2,r2,r2";
//	s[7] = "xorr10,r10,r10";
//	s[8] = "zjmp%:b0";
//	s[9] = "ldi%:p64deb,r6,r7";
//	s[10] = "stir7,r8,r6";
//	s[11] = "fork%:tirop";
//	s[12] = "lld%:go,r3";
//	s[13] = "lldir1,r2,r3";
//	s[14] = "lfork%42";
//	s[15] = "affr15";

	char **t;
	t[0] = "kek:";
	t[1] = "lolo:";
	t[2] = "1c:";
	t[3] = "fork:";

	t_strbag2 all_str;


	ft_bzero(&all_str, sizeof (all_str));
	for (int i = 0; i < 4; i++)
		lexer(t[i], &all_str);
}
