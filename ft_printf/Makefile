# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 14:33:40 by tnuyten           #+#    #+#              #
#    Updated: 2021/11/18 16:39:03 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =				ft_printf.c \
					ft_format_func1.c \
					ft_format_func2.c \
					libft_func.c

FILES = $(SRCS)

OBJS =			$(FILES:.c=.o)

CC =			gcc
RM =			rm -f
CFLAGS =		-Wall -Wextra -Werror

NAME =			libftprintf.a


all:			$(NAME)

$(NAME):		$(OBJS)
					ar rcs $(NAME) $(OBJS)

test: 			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)

bonus:
				@$(MAKE) BONUS_ADD=1 all


.PHONY:			all clean fclean re bonus
