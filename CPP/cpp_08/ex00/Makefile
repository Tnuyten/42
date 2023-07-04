# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 20:18:34 by tnuyten           #+#    #+#              #
#    Updated: 2023/07/02 17:46:57 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := easyfind
CXXFLAGS =  -Wall -Wextra -Werror -std=c++11
CXX = c++

SRCS =	main.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o: %.cpp easyfind.hpp easyfind.tpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS)      -o $(NAME) $(OBJS)

run:		all
			./$(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
