# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 14:33:40 by tnuyten           #+#    #+#              #
#    Updated: 2022/09/21 16:34:00 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			pipex.c \
				src/fork.c \
				src/free.c \
				src/parse.c \
				src/path.c

OBJS =			@$(SRCS:.c=.o)

CC =			clang
RM =			rm -f
CFLAGS =		#-fsanitize=address -g -O3#-Wall -Wextra -Werror #-fsanitize=address -g

NAME =			pipex

all:			ft_printf libft $(NAME)

lib/libft/libft.a: libft

lib/ft_printf/libftprintf.a: ft_printf

libft:
				@$(MAKE) -C lib/libft

ft_printf:
				@$(MAKE) -C lib/ft_printf

$(NAME):		$(OBJS) lib/libft/libft.a lib/ft_printf/libftprintf.a
					$(CC) $(OBJS) lib/libft/libft.a lib/ft_printf/libftprintf.a $(CFLAGS) -o $(NAME)

clean:
				$(RM) $(OBJS)
					@$(MAKE) -C lib/libft clean
					@$(MAKE) -C lib/ft_printf clean

fclean:			clean
					$(RM) $(NAME)
					@$(MAKE) -C lib/libft fclean
					@$(MAKE) -C lib/ft_printf fclean

re:				fclean all

.PHONY:			all clean fclean re libft ft_printf