/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukelly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 06:14:23 by ukelly            #+#    #+#             */
/*   Updated: 2021/01/10 06:14:24 by ukelly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <string.h>
#include <stdbool.h>
#include <logger.h>
#include "str.h"
#include "io_.h"
#include "ft_printf.h"
#include "conv.h"
static _Bool	check_name_the_file(char *name_the_file, char *file_extension)//fixed
{
	char	*tmp;

	tmp = strrchr(name_the_file, '.');

//	while (*tmp != '\0') - тут сега, strchr может возвр налл
//	{
//		if (*tmp != *file_extension)
//			return (false);
//		tmp++;
//		file_extension++;
//	}
//	return (true);
	return (ft_strequ(tmp, file_extension));
}

void	logger_show()
{
	logger_set_log_lvl(ALL);					//Глобальный уровень логгирования - все сообщеня ниже уровнем будут проигнорированы.
	logger_switch_flags(L_USE_COLORS, L_ENABLE);//Включаем/выключаем флаги
	logger_set_app_log_lvl(L_STDOUT, DEBUG);		//Локальный уровень логгирования - stdout логгирует сообщения уровня trace и выше
	logger_set_app_log_lvl(L_STDERR, ERROR);	//stderr будет логгировать только ошибки (самый большой уровень)

	logger_close();								//тушим
}

int		main(int ac, char **av)
{
	logger_show();	//
					//А также добавил всякого в math и conv
					//Добавил битовыйх, но оно вам не надо. Хотя хз. Посмотри
					//В string добавил склейку строк: ft_concat(2, "1", "2"); ft_concat(3, "1", "2". NULL);
					//В system ныне лежат	ft_mkpath - для создания пути папок
					//						ft_open_path - что выше + открывает файл на конце
	//ft_printf("%i", ft_atol("s00002"));
	logger_set_log_lvl(ALL);
	if (ac == 2 && check_name_the_file(*(av + 1), ".s"))
		assembler(*(av + 1));
	else if (ac == 2 && check_name_the_file(*(av + 1), ".cor"))
		;//disassembler(*(av + 1));
	else
		ft_putstr("usage: ./asm file_name\n");
	return (0);
}
