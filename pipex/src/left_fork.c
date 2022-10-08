#include "../pipex.h"

static int	set_pipe(t_prog *prog, int *fds, char *file)
{
	int	file_fd;

	if (access(file, R_OK) == -1)
	{
		perror(file);
		exit(EXIT_FAILURE);
	}
	fork_checks(prog);
	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
	{
		perror(file);
		return (-1);
	}
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
	close(fds[OUTPUT_END]);
	dup2(fds[INPUT_END], STDOUT_FILENO);
	close(fds[INPUT_END]);
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
		if (set_pipe(prog, fds, file) == -1)
			exit(EXIT_FAILURE);
		if (execve(prog->loc, prog->argv, NULL) == -1)
		{
			if (ft_strchr(prog->name, '/'))
				perror(prog->name);
			else
			{
				ft_putstr_fd(prog->name, 2);
				ft_putstr_fd(": command not found\n", 2);
				exit(127);
			}
		}
		exit(EXIT_FAILURE);
	}
	close(fds[INPUT_END]);
	return (pid);
}