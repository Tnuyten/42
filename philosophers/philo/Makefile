NAME := philo
CFLAG = #-g -fno-omit-frame-pointer -fsanitize=address
WFLAG = -Wall -Wextra -Werror
CC = clang

OBJ_DIR = obj
SRC_DIR = src

SRCS =	main.c\
		ft_atoi.c\
		ft_calloc.c\
		routine.c\
		routine_util.c\
		time.c\
		prepare.c\
		t_philo.c\
		cleanup.c

SRC = $(addprefix $(SRC_DIR)/,$(SRCS))
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

#Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all : $(NAME)

$(OBJ_DIR):
	mkdir $@

$(NAME): $(OBJ)
	$(CC) $(WFLAG) $(CFLAG) $(OBJ) -o $(NAME) -lpthread
	printf "$(_SUCCESS) $(NAME) ready.\n"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(WFLAG) -o $@ -c $^ $(CFLAG)

clean :
	test -e  $(OBJ_DIR) && rm -fr $(OBJ_DIR) || printf "$(_INFO) No objects to clean \n"

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
