#include "../pipex.h"

void ft_perror(char *str)
{
	char *s2 = ft_strjoin("pipex: ", str);
	perror(s2);
	free(s2);
}