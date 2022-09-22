#include "../pipex.h"
#include "hdr.h"

static char	*find_prog_in_path(char **paths, int path_size, char *prog_name)
{
	char	*prog_loc;
	char	*prog_path_temp;
	char	*prog_path;
	int		i;

	prog_loc = NULL;
	i = 0;
	while (i < path_size)
	{
		prog_path_temp = ft_strjoin(paths[i++], "/");
		prog_path = ft_strjoin(prog_path_temp, prog_name);
		free(prog_path_temp);
		if (access(prog_path, X_OK) == 0)
		{
			prog_loc = ft_strdup(prog_path);
			free(prog_path);
			break ;
		}
		free(prog_path);
	}
	return (prog_loc);
}

static int	count_spaces(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ' ')
		{
			count++;
		}
		str++;
	}
	return (count);
}

// malloc args + 3:
// +1 for NULL termination,
// +1 for the # of spaces being one less than # of words.
// +1 for the infile (NULL on the second pass, doesn't matter).
static char	**build_argv(char *prog, char **split)
{
	char	**args;
	int		i;

	args = (char **)malloc(sizeof(char *) * (count_spaces(prog) + 3));
	if (args == NULL)
		return (NULL);
	i = 0;
	while (split[i] != NULL)
	{
		args[i] = ft_strdup(split[i]);
		i++;
	}
	args[i] = NULL;
	return (args);
}

t_prog	*parse_args(char *prog, t_path *paths)
{
	t_prog	*pdata;
	char	**argv;
	char	**split;

	pdata = malloc(sizeof(t_prog));
	if (pdata == NULL)
		return (NULL);
	split = ft_split(prog, ' ');
	if (split == NULL)
	{
		free(pdata);
		return (NULL);
	}
	argv = build_argv(prog, split);
	if (argv == NULL)
	{
		free(pdata);
		free_split(split);
		return (NULL);
	}
	pdata->name = argv[0];
	pdata->argv = argv;
	pdata->loc = find_prog_in_path(paths->paths, paths->size, pdata->name);
	free_split(split);
	return (pdata);
}
