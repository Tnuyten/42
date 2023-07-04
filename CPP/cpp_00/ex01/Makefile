NAME := phonebookmanager
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++

SRCS =	main.cpp util.cpp #Phonebook.cpp Contact.cpp main.cpp util.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re