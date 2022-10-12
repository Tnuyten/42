/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:51:09 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/30 18:01:30 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "src/hdr.h"

static void	create_outfile(char *f2)
{
	int	fd;

	if (access(f2, F_OK) == -1)
	{
		fd = open(f2, O_CREAT, 0664);
		close(fd);
	}
}

static int	fork_wrap(int *fds, t_progs progs, char *const *argv)
{
	int	pid1;
	int	pid2;
	int	status;
	int	exit_status;

	exit_status = 0;
	create_outfile(argv[4]);
	pid1 = do_left_fork(fds, progs.p1, argv[1]);
	pid2 = do_right_fork(fds, progs.p2, argv[4]);
	waitpid(pid1, 0, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	return (exit_status);
}

int	main(int argc, char *const *argv, char **envp)
{
	t_progs	progs;
	char	**paths;
	int		pipe_x[2];
	int		exit_status;

	if (argc != 5)
	{
		ft_putstr_fd("Invalid arguments\n", 2);
		return (EXIT_FAILURE);
	}
	paths = split_path(envp);
	progs.p1 = parse_args(argv[2], paths);
	progs.p2 = parse_args(argv[3], paths);
	pipe(pipe_x);
	exit_status = fork_wrap(pipe_x, progs, argv);
	free_all(paths, progs);
	return (exit_status);
}
