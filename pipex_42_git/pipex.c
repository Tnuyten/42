/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:51:09 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/21 17:16:09 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "src/hdr.h"

static int	check_files(char *f1, char *f2, int *created)
{
	int fd;
	*created = 0;
	if (access(f1, F_OK | R_OK) == -1)
	{
		perror("File error");
		return (-1);
	}
	if (access(f2, F_OK) == -1)
	{
		fd = open(f2, O_CREAT);
		*created = 1;
		close(fd);
	}
	if (access(f2, W_OK) == -1)
	{
		perror("File error");
		if (created)
			unlink(f2);
		return (-1);
	}
	return (0);
}

static void	fork_wrap(int *fds, t_progs progs,
	char *const *argv, t_path *paths)
{
	int	created;

	if (check_files(argv[1], argv[4], &created) == -1)
	{
		free_pdata(progs.p1);
		free_pdata(progs.p2);
		free_paths(paths);
		exit(EXIT_FAILURE);
	}
	if (do_fork(fds, progs.p1, argv[1], 0) == -1)
	{
		if (created)
			unlink(argv[4]);
		free_all(paths, progs.p1, progs.p2, fds);
		exit(EXIT_FAILURE);
	}
	if (do_fork(fds, progs.p2, argv[4], 1) == -1)
	{
		if (created)
			unlink(argv[4]);
		free_all(paths, progs.p1, progs.p2, fds);
		exit(EXIT_FAILURE);
	}
}

static void	free_exit_on_parse_fail(t_prog *prog, t_prog *prev_prog,
	t_path *paths)
{
	if (prog == NULL)
	{
		if (prev_prog != NULL)
			free_pdata(prev_prog);
		free_paths(paths);
		exit(EXIT_FAILURE);
	}
	else if (prog->loc == NULL)
	{
		ft_printf("Program %s not found in path\n", prog->name);
		if (prev_prog != NULL)
			free_pdata(prev_prog);
		free_pdata(prog);
		free_paths(paths);
		exit(EXIT_FAILURE);
	}
}

// static void run()
// {
// 	system("leaks pipex");
// }

int	main(int argc, char *const *argv, char **envp)
{
	t_prog	*p1;
	t_prog	*p2;
	t_progs	progs;
	t_path	*paths;
	int		*fds;

	// atexit(run);

	if (argc != 5)
		return (EXIT_FAILURE);
	paths = split_path(envp);
	if (paths == NULL)
		return (EXIT_FAILURE);
	p1 = parse_args(argv[2], paths, argv[1]);
	free_exit_on_parse_fail(p1, NULL, paths);
	p2 = parse_args(argv[3], paths, NULL);
	free_exit_on_parse_fail(p2, p1, paths);
	fds = malloc(sizeof(int) * 2);
	pipe(fds);
	progs.p1 = p1;
	progs.p2 = p2;
	fork_wrap(fds, progs, argv, paths);
	free_all(paths, p1, p2, fds);
	return (EXIT_SUCCESS);
}
