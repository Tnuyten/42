/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:59:13 by tnuyten           #+#    #+#             */
/*   Updated: 2022/10/06 14:59:14 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_pdata(t_prog *pdata)
{
	int	i;

	if (pdata == NULL)
		return ;
	free(pdata->loc);
	free(pdata->name);
	i = 0;
	while (pdata->argv[i])
	{
		free(pdata->argv[i++]);
	}
	free(pdata->argv);
	free(pdata);
}

void	free_paths(char **paths)
{
	int	i;

	if (paths == NULL)
		return ;
	i = 0;
	while (paths[i])
	{
		free(paths[i++]);
	}
	free(paths);
}

void	free_all(char **paths, t_progs progs, int *fds)
{
	free_paths(paths);
	free_pdata(progs.p1);
	free_pdata(progs.p2);
	if (fds)
		free(fds);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
