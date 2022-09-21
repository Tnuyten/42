/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:13:08 by tnuyten           #+#    #+#             */
/*   Updated: 2022/09/12 15:42:10 by tnuyten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	queue_print(t_queue *queue)
{
	while (queue)
	{
		ft_printf("[%d]->", queue->number);
		queue = queue->next;
	}
	ft_printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_queue	*a;
	t_queue	*b;

	b = NULL;
	if (argc < 2)
		return (1);
	if (parse_input(&a, argc, argv))
	{
		ft_printf("%s\n", "Error");
		queue_clear(&a);
		return (1);
	}
	if (has_duplicates(a))
	{
		ft_printf("%s\n", "Error");
		queue_clear(&a);
		return (1);
	}
	sort(&a, &b);
	queue_clear(&a);
	queue_clear(&b);
	return (0);
}

/* PUSH_SWAP BONUS SHEET.
Bonus
Reminder : Remember that for the duration of the defence, no segfault, nor other unexpected, premature, uncontrolled or unexpected termination of the program, else the final grade is 0. Use the appropriate flag. This rule is active throughout the whole defence. We will look at your bonuses if and only if your mandatory part is EXCELLENT. This means that you must complete the mandatory part, beginning to end, and your error management needs to be flawless, even in cases of twisted or bad usage. So if the mandatory part didn't score all the point during this defence bonuses will be totally IGNORED.

Checker program - Error management

In this section, we'll evaluate the checker's error management.
If at least one fails, no points will be awarded for this
section. Move to the next one.

- Run checker with non numeric parameters. The program must
display "Error".

- Run checker with a duplicate numeric parameter. The program
must display "Error".

- Run checker with only numeric parameters including one greater
than MAXINT. The program must display "Error".

- Run checker without any parameters. The program must not
display anything and give the prompt back.

- Run checker with valid parameters, and write an action that
doesn't exist during the instruction phase. The program must
display "Error".

- Run checker with valid parameters, and write an action with
one or several spaces before and/or after the action during
the instruction phase. The program must display "Error".
Checker program - False tests

In this section, we'll evaluate the checker's ability to manage
a list of instructions that doesn't sort the list. Execute the
following 2 tests. If at least one fails, no points will be
awarded for this section. Move to the next one.

Don't forget to press CTRL+D to stop reading during the
intruction phase.

- Run checker with the following command "$>./checker 0 9 1 8 2
7 3 6 4 5" then write the following valid action list "[sa,
pb, rrr]". Checker should display "KO".

- Run checker with a valid list as parameter of your choice then
write a valid instruction list that doesn't order the
integers. Checker should display "KO". You'll have to
specifically check that the program wasn't developed to only
answer correctly on the test included in this scale. You
should repeat this test couple of times with several
permutations before you validate it.
Checker program - Right tests

In this section, we'll evaluate the checker's ability to manage
a list of instructions that sort the list. Execute the following
2 tests. If at least one fails, no points will be awarded for
this section. Move to the next one.

Don't forget to press CTRL+D to stop reading during the
instruction phase.

- Run checker with the following command "$>./checker 0 1 2"
then press CTRL+D without writing any instruction. The program
should display "OK".

- Run checker with the following command "$>./checker 0 9 1 8 2"
then write the following valid action list "[pb, ra, pb, ra,
sa, ra, pa, pa]". The program should display "OK".

- Run checker with a valid list as parameter of your choice then
write a valid instruction list that order the integers.
Checker must display "OK". You'll have to specifically check
that the program wasn't developed to only answer correctly on
the test included in this scale. You should repeat this test
couple of times with several permutations before you validate
it.

*/
