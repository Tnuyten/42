/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:59:18 by tnuyten           #+#    #+#             */
/*   Updated: 2022/10/06 14:59:19 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "hdr.h"

static char	*find_prog_in_path(char **paths, char *prog_name)
{
	char	*prog_loc;
	char	*prog_path_temp;
	char	*prog_path;
	int		i;

	if (prog_name == NULL)
		return (NULL);
	if (access(prog_name, X_OK) == 0)
		return (ft_strdup(prog_name));
	i = 0;
	if (paths == NULL)
		return (ft_strdup(prog_name));
	while (paths[i] != NULL)
	{
		prog_path_temp = ft_strjoin(paths[i++], "/");
		prog_path = ft_strjoin(prog_path_temp, prog_name);
		free(prog_path_temp);
		if (access(prog_path, X_OK) == 0)
		{
			prog_loc = ft_strdup(prog_path);
			free(prog_path);
			return (prog_loc);
		}
		free(prog_path);
	}
	return (ft_strdup(prog_name));
}

t_prog	*parse_args(char *prog, char **paths)
{
	t_prog	*pdata;
	char	**argv;

	pdata = malloc(sizeof(t_prog));
	if (pdata == NULL)
		return (NULL);
	argv = ft_split(prog, ' ');
	if (argv == NULL)
	{
		free(pdata);
		return (NULL);
	}
	pdata->name = argv[0];
	if (pdata->name == NULL)
		pdata->name = ft_strdup("");
	pdata->argv = argv;
	pdata->loc = find_prog_in_path(paths, pdata->name);
	// if (pdata->loc == NULL)
	// 	pdata->loc = ft_strdup("");
	return (pdata);
}
