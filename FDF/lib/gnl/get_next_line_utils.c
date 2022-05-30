/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:08:32 by tnuyten           #+#    #+#             */
/*   Updated: 2021/11/10 19:38:12 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int	count;

	count = 0;
	while (*c++)
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (start-- && *s)
		s++;
	i = 0;
	while (*s && len-- > 0)
		ptr[i++] = *s++;
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == '\0' && c == '\0')
			break ;
		else if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (dst == NULL && src == NULL && len != 0)
		return (NULL);
	s = src;
	d = dst;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		while (len)
		{
			*(d + len - 1) = *(s + len - 1);
			len--;
		}
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char *)s++) = '\0';
}
