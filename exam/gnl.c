#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*ft_strjoin(char *p1, char *p2);
char	*get_next_line(int fd);
int		 ft_strlen(char *str);


char	*get_next_line(int fd)
{
	static char buf[1];
	*buf = '\0';
	char *storage = malloc(sizeof(char) * 2);
	storage[0] = '\0';

	int stored = 1;
	while(*buf != '\n')
	{
		stored = read(fd, buf, 1);
		if(stored > 0)
			storage = ft_strjoin(storage, buf);
		else
			break;
	}

	if(stored == 0 && ft_strlen(storage) == 0)
	{
		free(storage);
		return (NULL);
	}

	return storage;
}

int ft_strlen(char *str)
{
	int c = 0;
	while(*str++)
	{
		c++;
	}

	return (c);
}

char *ft_strjoin(char *p1, char *p2)
{
	int len = ft_strlen(p1) + ft_strlen(p2);
	char *ptr = malloc(sizeof(char) * (len + 1));
	char *iter = ptr;
	char *c1 = p1;

	while(*p1)
	{
		*iter++ = *p1++;
	}
	while(*p2)
	{
		*iter++ = *p2++;
	}
	*iter = '\0';
	free(c1);
	return (ptr);
}

char	 *ft_strchr(char* ptr, char del)
{
	while (*ptr++ != del)
	{
		if (*ptr == '\0')
			return (NULL);
	}
	return ptr;
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("t1.txt", O_RDONLY);

	char *str = get_next_line(fd);
	int i = 0;
	while(str != NULL)
	{
		printf("%d: %s", i++, str);
		free(str);
		str = get_next_line(fd);

		if(str == NULL)
			return EXIT_SUCCESS;
	}
}
