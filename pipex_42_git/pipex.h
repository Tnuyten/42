/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:51:07 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/21 16:45:42 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <libc.h>

# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

int		evaluate(char *a, char *b);

typedef struct s_prog
{
	char	*name;
	char	*loc;
	char	**argv;
}	t_prog;

typedef struct s_progs
{
	t_prog	*p1;
	t_prog	*p2;
}	t_progs;

typedef struct s_path
{
	char	**paths;
	int		size;
}	t_path;

#endif