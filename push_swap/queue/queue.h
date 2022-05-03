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
t_queue	*queue_last(t_queue *queue);
int		queue_size(t_queue *queue);
void	queue_delone(t_queue *queue);
void	queue_clear(t_queue **queue);
int		queue_index(t_queue **root, t_queue *target);
t_queue* queue_get_node(t_queue **root, int num);
t_queue	*queue_copy(t_queue *root);

#endif