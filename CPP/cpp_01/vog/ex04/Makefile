NAME := notsed
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

SRCS =	main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)
	rm -f testfiles/*.replace

fclean : clean
	rm -f $(NAME)
	rm -f sed_test

re : fclean all

test : $(NAME)
	$(CXX) $(CXXFLAGS) test.cpp -o sed_test

.PHONY: all clean fclean re test