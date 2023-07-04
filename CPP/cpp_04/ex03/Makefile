NAME := mats
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

SRCS =	main.cpp \
		AMateria.cpp Cure.cpp Ice.cpp \
		Character.cpp \
		MateriaSource.cpp \

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re