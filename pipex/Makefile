# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 14:33:40 by tnuyten           #+#    #+#              #
#    Updated: 2022/10/12 19:54:59 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			pipex.c\
				src/left_fork.c\
				src/right_fork.c\
				src/free.c\
				src/parse.c\
				src/path.c\

OBJS =			$(SRCS:.c=.o)

CC =			clang
RM =			rm -f
CFLAGS =		-Wall -Wextra -Werror

NAME =			pipex

all:			libft $(NAME)

lib/libft/libft.a: libft


libft:
				@$(MAKE) -C lib/libft

$(NAME):		$(OBJS) lib/libft/libft.a
					$(CC) $(OBJS) lib/libft/libft.a $(CFLAGS) -o $(NAME)

clean:
				$(RM) $(OBJS)
					@$(MAKE) -C lib/libft clean

fclean:			clean
					$(RM) $(NAME)
					@$(MAKE) -C lib/libft fclean

re:				fclean all

.PHONY:			all clean fclean re libft