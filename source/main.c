#include "asm.h"
#include "lexer.h"
#include <string.h>
#include <fcntl.h>
# define MAX_SIZE_T 18446744073709551615ULL

/*
_Bool	check_name_the_file(char *name_the_file, char *file_extension)
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
*/

int		verificator_asm(char *argv)
{
    int32_t	len;

    len = ft_strlen(argv);
    if (!(ft_strequ(".s", &argv[len - 2])))
        return (1);
    return (0);
}

int     verificator_disasm(char *argv)
{
    int32_t	len;

    len = ft_strlen(argv);
    if (!(ft_strequ(".cor", &argv[len - 4])))
        return (1);
    return (0);
}

//void		wrong_inp(char *argv)
//{
//    ft_putstr("Wrong input \"%s\"\n");
//}

void    error_operations(void)
{
    ft_putstr("error op\n");
}

#include <stdio.h> //debug

int     find_start_cmd(char *s)
{
    if (s[0] ==  L || s[0] == S
        || s[0] == A || s[0] == O
        || s[0] == X || s[0] == Z
        || s[0] == F)
    {
        return (1);
    }
    else
        return (0);

}

int     find_cmd(char *s)
{
    if (ft_strnequ(s, LIVE, 4) || ft_strnequ(s, LD, 2)
    || ft_strnequ(s, LDI, 3) || ft_strnequ(s, LLD, 3)
    || ft_strnequ(s, LLDI, 4) || ft_strnequ(s, LFORK, 5)
    || ft_strnequ(s, ST, 2) || ft_strnequ(s, STI, 3 )
    || ft_strnequ(s, SUB, 3) || ft_strnequ(s, ADD, 3)
    || ft_strnequ(s, AND, 3) || ft_strnequ(s, AFF, 3)
    || ft_strnequ(s, OR, 2) || ft_strnequ(s, XOR, 3)
    || ft_strnequ(s, ZJMP, 4) || ft_strnequ(s, FORK, 4))
        return (1);
    return (0);
}

int     find_label(char *s)
{
	char *ret_s;
	if ((ret_s = ft_strchr(s, ':')))
		printf("%s\n", ret_s);
	return (0);
}

int     find_hash(char *s)
{
	char *ret_s;
	if ((ret_s = ft_strchr(s, '#')))
		printf("%s\n", ret_s);
	return (0);
}

t_strtype			find_start_str(char *s)
{
	t_strtype		finded;

	ft_bzero(&finded, sizeof(finded));
		if(find_cmd(s))
			finded.cmd = 1;
		else if(find_label(s))
			finded.label = 1;
		else if(find_hash(s))
			finded.hash_comm = 1;
	return (finded);
}

int     find_op(char *line)
{
    char *str;

    str = ft_strtrim(line);
    if ((find_start_str(str)).hash_comm)
    {
//        printf("%s\n", str);
    }
    return (0);
}

int     process_oper(int fd)
{
    char    *line;

    while (get_next_line(fd, &line) > 0)
    {
        find_op(line);
        free(line);
    }
    return (0);
}

void    core_op(int ac, char *av)
{
    int    fd = 0;

    if(((fd = open(av, O_RDONLY)) < 0))
    {
        ft_putstr("core_op2\n");                   //debug
//        wrong_inp(av);
    }
//    if (process_oper(fd) == 0)
    process_oper(fd);
}


int		main(int ac, char **av)
{

	if (ac == 2 && !(verificator_asm(av[1])))
    {
        core_op(ac, av[1]);
//		assembler(*(av + 1));
    }
	else if (ac == 2 && !(verificator_disasm(av[1])))
    {
	    ;
	//disassembler(*(av + 1));
    }
	else
		ft_putstr("usage: ./asm file_name\n");
	return (0);
}