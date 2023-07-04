NAME := zoo
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

SRCS =	main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

# %.o : %.cpp
# 	$(CXX) -o $@ -c $^ $(CXXFLAG)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re