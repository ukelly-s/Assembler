#include "asm.h"
#include "lexer.h"
#include <string.h>
#include <fcntl.h>
# define MAX_SIZE_T 18446744073709551615ULL
#include <stdio.h> //debu

static _Bool	check_name_the_file(char *name_the_file, char *file_extension)
{
	char	*tmp;

	tmp = strrchr(name_the_file, '.');//fixme strrchr -> ft_strrchr
	while (*tmp != '\0')
	{
		if (*tmp != *file_extension)
			return (false);
		tmp++;
		file_extension++;
	}
	return (true);
}

//void    error_operations(void)
//{
//    ft_putstr("error op\n");
//}

//int     find_label(char *s)
//{
//	char *ret_s;
//	if ((ret_s = ft_strchr(s, ':')))
//		printf("%s\n", ret_s);
//	return (0);
//}

//int     find_hash(char *s)
//{
//	char *ret_s;
//	if ((ret_s = ft_strchr(s, '#')))
//		printf("%s\n", ret_s);
//	return (0);
//}

//t_strtype			find_start_str(char *s)
//{
//	t_strtype		finded;
//
//	ft_bzero(&finded, sizeof(finded));
//		if(find_cmd(s))
//			finded.cmd = 1;
//		else if(find_label(s))
//			finded.label = 1;
//		else if(find_hash(s))
//			finded.hash_comm = 1;
//	return (finded);
//}

//int     find_op(char *line)
//{
//    char *str;
//
//    str = ft_strtrim(line);
//    if ((find_start_str(str)).hash_comm)
//    {
////        printf("%s\n", str);
//    }
//    return (0);
//}

//int     process_oper(int fd)
//{
//    char    *line;
//
//    while (get_next_line(fd, &line) > 0)
//    {
//        find_op(line);
//        free(line);
//    }
//    return (0);
//}

//void    core_op(int ac, char *av)
//{
//    int    fd = 0;
//
//    if(((fd = open(av, O_RDONLY)) < 0))
//    {
//        ft_putstr("core_op2\n");                   //debug
////        wrong_inp(av);
//    }
////    if (process_oper(fd) == 0)
//    process_oper(fd);
//}


int		main(int ac, char **av)
{
	if (ac == 2 && check_name_the_file(*(av + 1), ".s"))
		assembler(*(av + 1));
	else if (ac == 2 && check_name_the_file(*(av + 1), ".cor"))
		;//disassembler(*(av + 1));
	else
		ft_putstr("usage: ./asm file_name\n");
	return (0);
}