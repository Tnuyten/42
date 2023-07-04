# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 20:18:34 by tnuyten           #+#    #+#              #
#    Updated: 2023/04/21 16:00:55 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D
CFLAGS =  -Wall -Wextra -Werror -O3
EXTRAFLAGS = #-pedantic -Wconversion #-Weverything
ASAN = #-fsanitize=address -g -fno-omit-frame-pointer
CC = gcc
LIBMLX = ./lib/MLX42
LIBFT = ./lib/libft

LIBS = $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a -ldl -lglfw3 -pthread -lm -framework Cocoa -framework OpenGL -framework IOkit

SRCS =	src/cub3d.c \
		src/gnl/get_next_line.c \
		src/gnl/get_next_line_utils.c \
		src/parser/parse.c \
		src/parser/parse_util.c \
		src/parser/parse_line.c \
		src/validater/validate.c \
		src/validater/validate_util.c \
		src/minimap/minimap.c \
		src/minimap/player_icon.c \
		src/minimap/draw_ray.c \
		src/minimap/init_minimap.c \
		src/image/imagemanip.c \
		src/util/util.c \
		src/hooks/hooks.c \
		src/hooks/move_hooks.c \
		src/hooks/more_hooks.c \
		src/graphics/rays.c \
		src/graphics/texture.c \
		src/player/player_move.c \
		src/player/player.c \
		src/init/init.c \
		src/init/free.c \

OBJS = $(SRCS:.c=.o)

all : libft libmlx $(NAME)

mem:
	./memdetect.sh $(SRCS) $(LIBS) $(CFLAGS) $(ASAN) $(EXTRAFLAGS) -a own_maps/easy_map.cub -fail loop 

libft:
	@$(MAKE) -C $(LIBFT) -s

libmlx: libmlx_git
	@$(MAKE) -C $(LIBMLX) -s

libmlx_git:
	@git submodule update --init --recursive

%.o: %.c
	$(CC) $(CFLAGS) $(ASAN) $(EXTRAFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(ASAN) $(EXTRAFLAGS) $(LIBS) -o $(NAME) $(OBJS)

run:		all
			./$(NAME) "own_maps/easy_map.cub"

clean :
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(LIBMLX) clean

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(LIBMLX) fclean

re : fclean all

.PHONY: all clean fclean re libmlx
