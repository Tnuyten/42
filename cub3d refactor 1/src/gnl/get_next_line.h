/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:18:48 by tnuyten           #+#    #+#             */
/*   Updated: 2023/04/12 20:18:49 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4200
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_st
{
	char	*tmp;
	char	*re[1024];
	int		read[1024];
}t_st;
int			get_next_line(int fd, char **line);
int			ft_err(int fd, struct s_st *s);
size_t		ft_nl(char *s);
size_t		ft_size(char *s);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_jsf(char *s1, char *s2, int f);
char		*ft_strdup(const char *s);
#endif
