/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:59:20 by tnuyten           #+#    #+#             */
/*   Updated: 2022/10/06 14:59:21 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// return envp[i]+5 to cut off "PATH="
static char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	**split_path(char **envp)
{
	char	*path;
	char	**paths;

	path = find_path(envp);
	if (path == NULL)
		return (NULL);
	paths = ft_split(path, ':');
	return (paths);
}
