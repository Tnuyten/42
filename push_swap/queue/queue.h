#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

typedef struct s_queue
{
	int				number;
	struct s_queue	*next;
}	t_queue;

t_queue	*queue_new(int num);
void	queue_addback(t_queue **queue, t_queue *new_queue);
void	queue_addfront(t_queue **queue, t_queue *new_queue);
void	queue_delone(t_queue *queue);
void	queue_clear(t_queue **queue);

#endif