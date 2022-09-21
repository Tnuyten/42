#include "../pipex.h"

void	free_pdata(t_prog *pdata)
{
	int i;

	if (pdata == NULL)
		return ;
	free(pdata->loc);
	i = 0;
	while(pdata->argv[i])
	{
		free(pdata->argv[i++]);
	}
	free(pdata->argv);
	free(pdata);
}

void	free_paths(t_path *paths)
{
	int	i;

	i = 0;
	if (paths == NULL)
		return ;
	while (i < paths->size)
	{
		free(paths->paths[i++]);
	}
	free(paths->paths);
	free(paths);
}

void	free_all(t_path *paths, t_prog *p1, t_prog *p2, int *fds)
{
	free_paths(paths);
	free_pdata(p1);
	free_pdata(p2);
	free(fds);
}

void	free_split(char **split)
{
	int i = 0;
	while(split[i])
		free(split[i++]);
	free(split);
}
