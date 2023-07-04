# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 20:18:34 by tnuyten           #+#    #+#              #
#    Updated: 2023/06/27 19:24:40 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := templates
CXXFLAGS =  -Wall -Wextra -Werror -fsanitize=address -g
CXX = c++

SRCS =	main.cpp
TSRC =	test.cpp

OBJS = $(SRCS:.cpp=.o)
TOBJ = $(TSRC:.cpp=.o)

all : $(NAME)

%.o: %.cpp Array.hpp Array.tpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS)    -o $(NAME) $(OBJS)

test: $(TOBJ)
	$(CXX) $(CXXFLAGS)    -o test $(TOBJ)

run:		all
			./$(NAME)

clean :
	rm -f $(OBJS)
	rm -f $(TOBJ)
	rm -f test

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
