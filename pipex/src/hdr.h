/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:59:16 by tnuyten           #+#    #+#             */
/*   Updated: 2022/10/06 14:59:16 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HDR_H
# define HDR_H

# include "../pipex.h"

// Parse
char	**split_path(char **envp);
void	set_loc(t_prog *pdata, char **paths, t_prog *first_prog);
t_prog	*parse_args(char *prog, char **paths);

// Free
void	free_pdata(t_prog *pdata);
void	free_paths(char **paths);
void	free_all(char **paths, t_progs progs, int *fds);
void	free_split(char **split);
// Fork
int		do_left_fork(int *fds, t_prog *prog, char *file);
int		do_right_fork(int *fds, t_prog *prog, char *file);

#endif