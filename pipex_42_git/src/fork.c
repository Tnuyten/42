#include "../pipex.h"

#define INPUT_END 1
#define OUTPUT_END 0

static int	set_pipe(int *fds, char *file, int mode)
{
	int	file_fd;

	dprintf(2, "%d - %d: %d\n", fds[0], fds[1], mode);

	if (mode == 0)										// First fork.
	{
		close(fds[OUTPUT_END]);								// Close read end of pipe
		dup2(fds[INPUT_END], STDOUT_FILENO);				// Set STDOUT to read end of pipe. Data sent to STDOUT now goes to the pipe instead.
		close(fds[INPUT_END]);								// Close the write end of the pipe.
	}
	else												// Second fork.
	{
		close(fds[INPUT_END]);								// Close write end of pipe.
		dup2(fds[OUTPUT_END], STDIN_FILENO);				// Set STDIN to read end of pipe. Reading from STDIN now reads from the pipe instead.
		close(fds[OUTPUT_END]);								// Close read end of pipe.
		file_fd = open(file, O_WRONLY);
		if (file_fd == -1)
		{
			perror("Could not open file");
			return (-1);
		}
		close(file_fd);
		dup2(file_fd, STDOUT_FILENO);				// Set STDOUT to outfile. Data written to STDOUT is written to outfile instead.
	}
	return (0);
}

static void	do_execve(t_prog *prog)
{
	if (execve(prog->loc, prog->argv, NULL) == -1)
	{
		perror("Execve error");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}

static int	parent_wait(int pid)
{
	int	status;

	if (pid == waitpid(pid, &status, 0))
	{
		if (WEXITSTATUS(status) == 1)
			return (-1);
	}
	return (0);
}

int	do_fork(int *fds, t_prog *prog, char *file, int mode)
{
	int	pid;
	int	file_fd;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		if (mode == 0)										// First fork.
		{
			dup2(fds[INPUT_END], STDOUT_FILENO);				// Set STDOUT to read end of pipe. Data sent to STDOUT now goes to the pipe instead.
			close(fds[OUTPUT_END]);								// Close read end of pipe
			close(fds[INPUT_END]);								// Close the write end of the pipe.
		}
		else												// Second fork.
		{
			dup2(fds[OUTPUT_END], STDIN_FILENO);				// Set STDIN to read end of pipe. Reading from STDIN now reads from the pipe instead.
			close(fds[INPUT_END]);								// Close write end of pipe.
			close(fds[OUTPUT_END]);								// Close read end of pipe.
			file_fd = open(file, O_WRONLY);
			if (file_fd == -1)
			{
				perror("Could not open file");
				exit(EXIT_FAILURE);
			}
			dup2(file_fd, STDOUT_FILENO);				// Set STDOUT to outfile. Data written to STDOUT is written to outfile instead.
			close(file_fd);
		}
		if (execve(prog->loc, prog->argv, NULL) == -1)
		{
			perror("Execve error");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
	}
	close(fds[OUTPUT_END]);
	close(fds[INPUT_END]);

	if (pid == waitpid(pid, &status, 0))
	{
		if (WEXITSTATUS(status) == 1)
			return (-1);
	}
	return (0);
}
// return (parent_wait(pid));
//if(mode == 1) //You'd think I have to get rid of this, and always close both ends of the pipe, but many commands work when I don't, and don't when I do.
