#include <stdio.h>
#include <string.h>

#include <fcntl.h>
#include <sys/syslimits.h>

void	cleanup(int fd, char *line);
int		file_path(int fd, char *fp);
void	correct();
void	wrong();
void	test(int fd, char *expected_output);