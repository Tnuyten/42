/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:33:38 by tnuyten           #+#    #+#             */
/*   Updated: 2023/02/08 18:55:21 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

void	*ft_calloc(int count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	else
		errno = ENOMEM;
	return (ptr);
}
