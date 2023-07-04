NAME := cub3d
CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
LIBMLX = ./lib/MLX42

HEADERS = -I ./include -I $(LIBMLX)/include
LIBS = $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm

SRCS =	cub3d.c
OBJS = $(SRCS:.c=.o)

all : libmlx $(NAME)

libmlx:
	$(MAKE) -C $(LIBMLX)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(HEADERS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)
	$(MAKE) -C $(LIBMLX) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBMLX) fclean

re : fclean all

.PHONY: all clean fclean re libmlx