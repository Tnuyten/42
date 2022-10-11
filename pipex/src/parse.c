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

static char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	tmp = ft_strjoin(s1, s2);
	if (tmp == NULL)
		return (NULL);
	ret = ft_strjoin(tmp, s3);
	free(tmp);
	return (ret);
}

static char	*find_prog_in_path(char **paths, char *prog_name)
{
	char	*prog_path;
	int		i;

	if (prog_name == NULL)
		return (NULL);
	if (ft_strchr(prog_name, '/') || access(prog_name, X_OK) == 0)
		return (ft_strdup(prog_name));
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		prog_path = ft_strjoin3(paths[i++], "/", prog_name);
		if (prog_path == NULL)
			return (NULL);
		if (access(prog_path, X_OK) == 0)
			return (prog_path);
		free(prog_path);
	}
	return (NULL);
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
	pdata->argv = argv;
	if (argv[0])
		pdata->name = ft_strdup(argv[0]);
	else
		pdata->name = ft_strdup("");
	pdata->loc = find_prog_in_path(paths, pdata->name);
	return (pdata);
}
