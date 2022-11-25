NAME := philo
<<<<<<< HEAD
CFLAG = -lpthread -g -fno-omit-frame-pointer#-fsanitize=thread
WFLAG = -Wall -Wextra #-Werror
CC = gcc
=======
CFLAG = -lpthread -g #-fsanitize=thread -O3
WFLAG = -Wall -Wextra #-Werror
CC = clang
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694

SRC =	src/main.c\
		src/ft_atoi.c\
		src/ft_calloc.c\
		src/routine.c\
		src/time.c\
<<<<<<< HEAD
		src/prepare.c\
=======
		src/parse.c\
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
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
<<<<<<< HEAD
	@$(CC) $(WFLAG) $(CFLAG) $(OBJ) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) ready.\n"

obj/%.o : src/%.c
	@$(CC) $(WFLAG) -o $@ -c $^ $(CFLAG)
=======
	@$(CC) $(CFLAG) $(OBJ) -o $(NAME) $(WFLAG)
	@printf "$(_SUCCESS) $(NAME) ready.\n"

obj/%.o : src/%.c
	@$(CC) $(CFLAG) -o $@ -c $^ $(WFLAG)
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694

clean :
	@test -e obj && rm -fr obj || printf "$(_INFO) No objects to clean \n"

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
<<<<<<< HEAD

	# Forks: 0x4A7F0B0
	# Fork[0]: 0x4A7F0B0
	# Fork[1]: 0x4A7F0D8
	# Fork[2]: 0x4A7F100
	# Fork[3]: 0x4A7F128
	# Fork[4]: 0x4A7F150
=======
>>>>>>> c8347a0c1c8a079ef9de6aacc40cb6a81c3ef694
