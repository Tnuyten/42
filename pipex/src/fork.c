#include "../pipex.h"

#define INPUT_END 1
#define OUTPUT_END 0

static int	set_left_pipe(int *fds, char *file)
{
	int	file_fd;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
	{
		perror("Could not open file");
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
	file_fd = open(file, O_WRONLY);
	if (file_fd == -1)
	{
		perror("Could not open file");
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
		if (set_left_pipe(fds, file) == -1)
			exit(EXIT_FAILURE);
		if (execve(prog->loc, prog->argv, NULL) == -1)
		{
			perror("Execve error");
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
		if (set_right_pipe(fds, file) == -1)
			exit(EXIT_FAILURE);
		if (execve(prog->loc, prog->argv, NULL) == -1)
		{
			perror("Execve error");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
	}
	close(fds[OUTPUT_END]);
	close(fds[INPUT_END]);
	return (pid);
}
