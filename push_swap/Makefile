# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 14:33:40 by tnuyten           #+#    #+#              #
#    Updated: 2022/07/04 18:31:23 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PS_SRCS =			push_swap.c

SRCS =				queue/queue.c \
					queue/queue_get.c \
					queue/queue_operations_push.c \
					queue/queue_operations_swap.c \
					queue/queue_operations_rotate.c \
					queue/queue_operations_reverse_rotate.c \
					sort/sort_queue.c \
					sort/sort_queue_helpers.c \
					sort/sort_queue_helpers_more.c \
					parse/parse.c


BONUS_SRCS = 		get_next_line/get_next_line.c \
					bonus/checker.c

PS_OBJS = 		$(PS_SRCS:.c=.o)
OBJS =			$(SRCS:.c=.o)
BONUS_OBJS = 	$(BONUS_SRCS:.c=.o)

CC =			clang
RM =			rm -f
CFLAGS =		-Wall -Wextra -Werror #-fsanitize=address -g3 -g

NAME =			push_swap
CHECKER_NAME =	checker


all:			libft ft_printf $(NAME)


libft:
					@$(MAKE) -C libft


ft_printf:
					@$(MAKE) -C ft_printf

libft/libft.a: libft

ft_printf/libftprintf.a: ft_printf

$(NAME):			$(OBJS) $(PS_OBJS) libft/libft.a ft_printf/libftprintf.a
					$(CC) $(CFLAGS) $(OBJS) $(PS_OBJS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)


$(CHECKER_NAME):	$(OBJS) $(BONUS_OBJS) libft/libft.a ft_printf/libftprintf.a $(NAME)
						$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) libft/libft.a ft_printf/libftprintf.a -o $(CHECKER_NAME)

clean:
					$(RM) $(OBJS)
					$(RM) $(PS_OBJS)
					$(RM) $(NAME)_leaks
					$(RM) $(BONUS_OBJS)
						@$(MAKE) -C libft clean
						@$(MAKE) -C ft_printf clean


fclean:				clean
						$(RM) $(NAME)
						$(RM) $(CHECKER_NAME)
						$(RM) .tmp_leaks.c
						@$(MAKE) -C libft fclean
						@$(MAKE) -C ft_printf fclean


re:					fclean all


bonus:				libft ft_printf $(CHECKER_NAME)

MAIN_PATH=./push_swap.c
$(NAME)_leaks: $(OBJS) $(PS_OBJS) libft/libft.a ft_printf/libftprintf.a
	# $(eval main_proto=$(shell grep 'int\tmain' $(MAIN_PATH)))
	# $(eval leaks_proto=$(shell echo '$(main_proto)' | sed 's/main/leaks_tester/'))
	# $(eval call_main=$(shell echo '$(main_proto)' | sed -E "s/(int| |\*|char|const|void|\[|\])//g"))
	# @echo '#include "stdlib.h"\n\n\
	# $(main_proto);\n\n\
	# $(leaks_proto) {\n\
	# 	\tint exitcode = $(call_main);\n\
	# 	\tsystem("leaks $(NAME)_leaks");\n\
	# 	\treturn (exitcode);\n\
	# }' > .tmp_leaks.c
	$(CC) $(CFLAGS) $(OBJS) $(PS_OBJS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)_leaks .tmp_leaks.c -e_leaks_tester
	# @rm .tmp_leaks.c

leaks: $(NAME)_leaks


.PHONY:			all clean fclean re libft ft_printf
