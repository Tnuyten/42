#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../../lib/libft/libft.h"

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# if BUFFER_SIZE > INT_MAX
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*do_read(int fd, char *buf, char *storage, ssize_t *stored);
char	*get_next_line(int fd);
char	*take_line_from_buffer(char *buf);

#endif
