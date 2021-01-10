////
//// Created by Alethia Eclipso on 1/10/21.
////
//
//#include "lexer.h"
//
//int     cmd_l(char *s, t_cmd **cmd)
//{
//	if (s[1] == I)
//	{
//		if (s[2] == V && s[3] == E)
//		{
//			do_livejmpfork(s, cmd, LIVE);
//		}
//	}
//	else if (s[1] == D)
//	{
//		if (s[2] != I)
//			printf("this is ld\n");
//		else if (s[2] == I)
//			printf("this is ldi\n");
//	}
//	else if (s[1] == L)
//	{
//		if (s[2] == D)
//		{
//			if (s[3] != I)
//				printf("this is lld\n");
//			else if (s[3] == I)
//				printf("this is lldi\n");
//		}
//	}
//	else if (s[1] == F)
//	{
//		if (s[2] == O && s[3] == R && s[4] == K)
//		{
//			do_livejmpfork(s, cmd, LFORK);
//		}
//	}
//	return (0);
//}
//
//int     cmd_s(char *s, t_cmd **cmd)
//{
//	if (s[1] == T)
//	{
//		if (s[2] != I)
//			printf("this is st\n");
//		else if (s[2] == I)
//			printf("this is sti\n");
//	}
//	else if (s[1] == U)
//	{
//		if (s[2] == B)
//			printf("this is sub\n");
//		else if(s[2] != B)
//			printf("NOT SUB..");
//	}
//	return (0);
//}
//
//int     cmd_a(char *s, t_cmd **cmd)
//{
//	if (s[1] == D && s[2] == D)
//		printf("this is add\n");
//	else if (s[1] == N && s[2] == D)
//		printf("this is and\n");
//	else if (s[1] == F && s[2] == F)
//		printf("this is aff\n");
//	return (0);
//}
//
//int		find_cmd_tree(char *s, t_cmd **cmd)
//{
//	if (s[0] == L)
//		cmd_l(s, cmd);
//	else if (s[0] == S)
//		cmd_s(s, cmd);
//	else if (s[0] == A)
//		cmd_a(s, cmd);
//	else if (s[0] == O && s[1] == R)
//		printf("this is or\n");
//	else if (s[0] == X && s[1] == O && s[2] == R)
//		printf("this is xor\n");
//	else if (s[0] == Z && s[1] == J && s[2] == M && s[3] == P)
//		do_livejmpfork(s, cmd, ZJMP);
//	else if (s[0] == F && s[1] == O && s[2] == R && s[3] == K)
//		do_livejmpfork(s, cmd, FORK);
//	else
//		printf("not founded\n");
//	return 0;
//}