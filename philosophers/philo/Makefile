NAME := philo
OBJ_DIR = ./obj
CFLAG = -Wall -Wextra -Werror -lpthread -fsanitize=thread
CC = clang

SRC =	philo.c\
		ft_atoi.c\
		philosopher.c\

OBJ = $(SRC:.c=.o)
#Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAG) $(OBJ) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) ready.\n"

clean :
	@test -e obj && rm -fr obj || printf "$(_INFO) No objects to clean \n"
	rm *.o

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
