# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 14:33:40 by tnuyten           #+#    #+#              #
#    Updated: 2022/04/14 15:27:32 by tnuyten          ###   ########.fr        #
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

# BONUS_SRCS =			ft_lstnew.c \
# 						ft_lstadd_front.c \
# 						ft_lstsize.c \
# 						ft_lstlast.c \
# 						ft_lstadd_back.c \
# 						ft_lstdelone.c \
# 						ft_lstclear.c \
# 						ft_lstmap.c \
# 						ft_lstiter.c

ifdef	BONUS_ADD
	FILES = $(SRCS) $(BONUS_SRCS)
else
	FILES = $(SRCS)
endif

BFILES = $(SRCS) $(BONUS_SRCS)

OBJS =			$(FILES:.c=.o)
BONUS_OBJS =	$(BFILES:.c=.o)

CC =			gcc
RM =			rm -f
CFLAGS =		-Wall -Wextra -Werror

NAME =			push_swap


all:			$(NAME)

$(NAME):		$(OBJS)
					# ar rcs $(NAME) $(OBJS)

test: 			$(NAME)

clean:
				$(RM) $(BONUS_OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)

bonus:
				@$(MAKE) BONUS_ADD=1 all


.PHONY:			all clean fclean re bonus
