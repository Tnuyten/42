#include <stdio.h>
#include "parse.h"

//debug function, will be removed. #TODO remove
void	print_map(char **map)
{
	while (*map != NULL)
	{
		printf("%s\n", *map++);
	}
}

int	ft_fnl(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int	is_texture_line(char *line)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = ft_strnstr(line, "NO ", ft_strlen(line)) != NULL;
	b = ft_strnstr(line, "SO ", ft_strlen(line)) != NULL;
	c = ft_strnstr(line, "EA ", ft_strlen(line)) != NULL;
	d = ft_strnstr(line, "WE ", ft_strlen(line)) != NULL;
	return (a || b || c || d);
}

int	is_color_line(char *line)
{
	int	a;
	int	b;

	a = ft_strnstr(line, "F ", ft_strlen(line)) != NULL;
	b = ft_strnstr(line, "C ", ft_strlen(line)) != NULL;
	return (a || b);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

int	is_map_line(char *line)
{
	int	res;

	res = (!is_texture_line(line)
			&& !is_color_line(line)
			&& !is_empty_line(line));
	return (res);
}
