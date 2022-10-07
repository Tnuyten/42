/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:59:06 by tnuyten           #+#    #+#             */
/*   Updated: 2022/10/06 14:59:07 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

#define INPUT_END 1
#define OUTPUT_END 0

static int	set_left_pipe(int *fds, char *file)
{
	int	file_fd;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
	{
		ft_perror(file);
		return (-1);
	}
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
	close(fds[OUTPUT_END]);
	dup2(fds[INPUT_END], STDOUT_FILENO);
	close(fds[INPUT_END]);
	return (0);
}

static int	set_right_pipe(int *fds, char *file)
{
	int	file_fd;

	close(fds[INPUT_END]);
	dup2(fds[OUTPUT_END], STDIN_FILENO);
	close(fds[OUTPUT_END]);
	file_fd = open(file, O_WRONLY | O_TRUNC);
	if (file_fd == -1)
	{
		ft_perror(file);
		return (-1);
	}
	dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
	return (0);
}

int	do_left_fork(int *fds, t_prog *prog, char *file)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (prog == NULL)
			exit(EXIT_FAILURE);
		if (access(file, R_OK) == -1)
		{
			dprintf(2, "%s\n", "testflap");
			ft_perror(file);
			exit(EXIT_FAILURE);
		}
		if (set_left_pipe(fds, file) == -1)
			exit(EXIT_FAILURE);
		if (execve(prog->loc, prog->argv, NULL) == -1)
		{
			if (ft_strchr(prog->name, '/'))
				ft_perror(prog->name);
			else
			{
				ft_putstr_fd("pipex: ", 2);
				ft_putstr_fd(prog->name, 2);
				ft_putstr_fd(": command not found\n", 2);
				exit(127);
			}
			exit(EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
	}
	close(fds[INPUT_END]);
	return (pid);
}

int	do_right_fork(int *fds, t_prog *prog, char *file)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (prog == NULL)
			exit(EXIT_FAILURE);
		if (access(file, W_OK) == -1)
		{
			ft_perror(file);
			exit(EXIT_FAILURE);
		}
		if (set_right_pipe(fds, file) == -1)
			exit(EXIT_FAILURE);
		if (execve(prog->loc, prog->argv, NULL) == -1)
		{
			if (ft_strchr(prog->name, '/'))
				ft_perror(prog->name);
			else
			{
				ft_putstr_fd("pipex: ", 2);
				ft_putstr_fd(prog->name, 2);
				ft_putstr_fd(": command not found\n", 2);
				exit(127);
			}
		}
		exit(EXIT_FAILURE);
	}
	close(fds[OUTPUT_END]);
	close(fds[INPUT_END]);
	return (pid);
}
