NAME := cub3d
CFLAGS =  -Wall -Wextra -fsanitize=address -g #-pedantic #-Wconversion #-Weverything #-Werror
CC = gcc
LIBMLX = ./lib/MLX42
LIBFT = ./lib/libft

LIBS = $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a -ldl -lglfw3 -pthread -lm -framework Cocoa -framework OpenGL -framework IOkit
HEADER = src/cub3d.h \
		src/

SRCS =	src/cub3d.c \
		src/gnl/get_next_line.c \
		src/parser/parse.c \
		src/parser/parse_util.c \
		src/validater/validate.c \
		src/graphics/background.c \
		src/minimap/minimap.c \
		src/minimap/draw_player.c \
		src/image/imagemanip.c \
		src/util/util.c \
		src/hooks/hooks.c \
		src/hooks/move_hooks.c \
		src/graphics/rays.c \
		src/graphics/texture.c \
		src/player/player_move.c \
		src/player/player.c \

OBJS = $(SRCS:.c=.o)

all : libft libmlx $(NAME)

libft:
	$(MAKE) -C $(LIBFT)

libmlx: libmlx_git
	$(MAKE) DEBUG=1 -C $(LIBMLX) #TODO remove debug

libmlx_git:
	git submodule update --init --recursive

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(LIBS) -o $(NAME) $(OBJS)

run:		$(NAME)
			./$(NAME) "easy_map.txt"

clean :
	rm -f $(OBJS)
#	$(MAKE) -C $(LIBMLX) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBMLX) fclean
	$(MAKE) -C $(LIBFT) fclean

re : clean all

remake : fclean all

.PHONY: all clean fclean re libmlx