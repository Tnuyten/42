# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.codam.nl>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 14:33:40 by tnuyten           #+#    #+#              #
#    Updated: 2022/08/25 17:48:47 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =			fdf.c \
				src/line/line.c \
				src/iso/iso.c \
				src/map/map.c \
				src/math/math.c \
				src/draw/draw.c \
				src/draw/draw_helpers.c \
				src/hooks/hooks.c \
				lib/gnl/get_next_line.c \
				lib/gnl/get_next_line_utils.c \

OBJS =			$(SRCS:.c=.o)

CC =			clang
RM =			rm -f
CFLAGS =		-Imlx -Wall -Wextra -Werror #-fsanitize=address -g

NAME =			fdf

all:			ft_printf libft $(NAME)

lib/libft/libft.a: libft

lib/ft_printf/libftprintf.a: ft_printf

libft:
				@$(MAKE) -C lib/libft

ft_printf:
				@$(MAKE) -C lib/ft_printf

$(NAME):		$(OBJS) lib/libft/libft.a lib/ft_printf/libftprintf.a
					$(CC) $(OBJS) lib/libft/libft.a lib/ft_printf/libftprintf.a -Llib/mlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS) -o $(NAME)

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