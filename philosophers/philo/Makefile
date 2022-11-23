NAME := philo
CFLAG = -lpthread -g #-fsanitize=thread -O3
WFLAG = -Wall -Wextra #-Werror
CC = clang

SRC =	src/main.c\
		src/ft_atoi.c\
		src/ft_calloc.c\
		src/routine.c\
		src/time.c\
		src/parse.c\
		src/t_philo.c\

OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))
#Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all : $(NAME)

obj_folder :
	@mkdir -pv obj

$(NAME): obj_folder $(OBJ)
	@$(CC) $(CFLAG) $(OBJ) -o $(NAME) $(WFLAG)
	@printf "$(_SUCCESS) $(NAME) ready.\n"

obj/%.o : src/%.c
	@$(CC) $(CFLAG) -o $@ -c $^ $(WFLAG)

clean :
	@test -e obj && rm -fr obj || printf "$(_INFO) No objects to clean \n"

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
