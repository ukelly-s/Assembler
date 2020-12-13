
#include "asm.h"

void	free_str(char **s, char ***arr, int i)
{
	int		j;

	if ((i == 1 || i == 2) && *s != 0)
	{
		free(*s);
		*s = 0;
	}
	if ((i == 0 || i == 2) && arr != 0 && *arr != 0)
	{
		j = 0;
		while (arr[0][j])
		{
			free(arr[0][j]);
			arr[0][j] = 0;
			j++;
		}
		free(*arr);
		*arr = 0;
	}
}

int 	get_clean_str(t_parser *assm, char **str)
{
	char 	*line;
	char 	*tmp;
	int 	ret;
	char 	**arr;

	ret = get_next_line(assm->fd, &line);
	if (ret > 0) {
		tmp = ft_strtrim(line);
		free_str(&line, NULL, 1);
		if (tmp == NULL || ft_strlen(tmp) == 0) {
			*str = ft_strdup("");
			free_str(&tmp, NULL, 1);
			return (ret);
		}
		arr = 0;
		if (tmp[0] == COMMENT_CHAR || tmp[0] == ALT_COMMENT_CHAR)
			*str = ft_strdup("");
		else if (ft_strchr(tmp, COMMENT_CHAR))
			arr = ft_strsplit(tmp, COMMENT_CHAR);
		else
			arr = ft_strsplit(tmp, ALT_COMMENT_CHAR);
		if (arr != 0 && ft_strlen(arr[0]) > 0)
			*str = ft_strdup(arr[0]);
		free_str(&tmp, &arr, 2);
	}
	return (ret);
}

void	basic_parse(t_parser *assm, char *tmp)
{
	char	**arr;

	if (ft_strchr(tmp, COMMENT_CHAR))
		arr = ft_strsplit(tmp, COMMENT_CHAR);
	else
		arr = ft_strsplit(tmp, ALT_COMMENT_CHAR);
	if (ft_strlen(tmp) > 0 && tmp[0] != COMMENT_CHAR && tmp[0] != ALT_COMMENT_CHAR)
	{
		if (ft_strncmp(arr[0], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
			;//get name comment
		else if (ft_strncmp(arr[0], COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) == 0)
			;//get name comment
		else
			;//get  labels
	}
	free_str(NULL, &arr, 0);
}

void	*parse(t_parser *assm)
{
	char		*line;


	while (get_clean_str(assm, &line) > 0)
	{
		assm->line++;
		if (ft_strlen(line) > 0)
			basic_parse(assm, line); // парсинг коментов+инструкций+меток и тд
		free_str(&line, NULL, 1);
	}
//	free_str(&line, NULL, 1);
//	while (get_next_line(assm->fd, &line) > 0)
//	{
//		if ()
//			;
//		else if ()
//			;
//		else
//			ft_kill("Error", NULL, __func__, __FILE__);
//	}

}