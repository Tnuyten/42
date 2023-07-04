NAME := clapped
CFLAG = -Wall -Wextra -Werror -std=c++98
CC = c++

SRCS =	main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAG)

%.o : %.cpp
	$(CC) -o $@ -c $^ $(CFLAG)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re