# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 14:33:40 by tnuyten           #+#    #+#              #
#    Updated: 2022/04/15 21:09:45 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =				push_swap.c \
					queue/queue.c \
					queue/queue_operations_push.c \
					queue/queue_operations_swap.c \
					queue/queue_operations_rotate.c \
					queue/queue_operations_reverse_rotate.c \
					sort/sort_queue.c \
					sort/sort_queue_helpers.c \
					sort/sort_queue_helpers_more.c \
					debug.c

FILES = $(SRCS)

OBJS =			$(FILES:.c=.o)

CC =			gcc
RM =			rm -f
CFLAGS =		-Wall -Wextra -Werror

NAME =			push_swap


all:			libft ft_printf $(NAME)

libft:
				@$(MAKE) -C libft

ft_printf:
				@$(MAKE) -C ft_printf

$(NAME):		$(OBJS) libft/libft.a ft_printf/libftprintf.a

clean:
				$(RM) $(OBJS)
					@$(MAKE) -C libft clean
					@$(MAKE) -C ft_printf clean


fclean:			clean
					$(RM) $(NAME)
					@$(MAKE) -C libft fclean
					@$(MAKE) -C ft_printf fclean

re:				fclean $(NAME)

.PHONY:			all clean fclean re libft ft_printf
