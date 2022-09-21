#ifndef HDR_H
# define HDR_H

# include "../pipex.h"

// Parse_PATH
t_path	*split_path(char **envp);
void	set_loc(t_prog *pdata, t_path *paths, t_prog *first_prog);
t_prog	*parse_args(char *prog, t_path *paths, char *infile);

// Free
void	free_pdata(t_prog *pdata);
void	free_paths(t_path *paths);
void	free_all(t_path *paths, t_prog *p1, t_prog *p2, int *fds);
void	free_split(char **split);
// Fork
int		do_fork(int *fds, t_prog *prog, char *file, int mode);

#endif