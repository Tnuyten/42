#include "queue/queue.h"

#include <stdio.h> //#TODO REMOVE

//#TODO fix dis with ft_printf.
void	print_queue(char *name, t_queue *queue)
{
	printf("Queue: %s[", name);
	if (queue == NULL)
	{
		printf("%s\n", "empty]");
		return ;
	}
	while (queue->next != NULL)
	{
		printf("%d - ", queue->number);
		queue = queue->next;
	}
	printf("%d]\n", queue->number);
}

//https://stackoverflow.com/questions/38164849/sorting-a-queue-in-ascending-order-in-c-using-two-queues

// With 3 numbers, we need to sort it with not more than 3 instructions.
// With 5 numbers, we need to sort it with not more than 12 instructions.
// With 100 numbers, we can get
// 		5 points if the size of the list of instructions is less than 700
// 		4 points if the size of the list of instructions is less than 900
// 		3 points if the size of the list of instructions is less than 1100
// 		2 points if the size of the list of instructions is less than 1300
// 		1 points if the size of the list of instructions is less than 1500
// With 500 numbers, we can get
// 		5 points if the size of the list of instructions is less than 5500
// 		4 points if the size of the list of instructions is less than 7000
// 		3 points if the size of the list of instructions is less than 8500
// 		2 points if	 the size of the list of instructions is less than 10000
// 		1 points if the size of the list of instructions is less than 11500
// According to unreliable sources, we need to get at least 6 points to pass.

// import random
// print(random.sample(range(100), 10))

// import random
// print(random.sample(range(-10000,10000), 500))

// https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

// https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

// https://gitlab.com/42cursus-wetieven/23-push-swap

// https://github.com/klasak/push_swap_new


/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2

2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1

3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1

4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
*/