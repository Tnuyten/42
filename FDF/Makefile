# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 14:33:40 by tnuyten           #+#    #+#              #
#    Updated: 2022/05/18 17:39:13 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			fdf.c \
				line/line.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c

FILES = 		$(SRCS)

OBJS =			$(FILES:.c=.o)

CC =			gcc
RM =			rm -f
CFLAGS =		-Imlx #-Wall -Wextra -Werror

NAME =			fdf


all:			libft $(NAME)

libft:
				@$(MAKE) -C libft

$(NAME):		$(OBJS) libft/libft.a
					$(CC) $(OBJS) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS) -o $(NAME)

clean:
				$(RM) $(OBJS)
					@$(MAKE) -C libft clean

fclean:			clean
					$(RM) $(NAME)
					@$(MAKE) -C libft fclean

re:				fclean all

.PHONY:			all clean fclean re libft
