/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:51:07 by tnuyten           #+#    #+#             */
/*   Updated: 2022/10/06 15:00:53 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
// # include <libc.h>
# include <sys/wait.h>
# include <stdio.h>

# include "lib/libft/libft.h"

#define INPUT_END 1
#define OUTPUT_END 0

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

void	fork_checks(t_prog *prog);

#endif
