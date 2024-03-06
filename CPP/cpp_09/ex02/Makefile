# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 20:18:34 by tnuyten           #+#    #+#              #
#    Updated: 2023/09/15 19:55:04 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := PmergeMe
CXXFLAGS =  -Wall -Wextra -Werror -std=c++11 
# CXXFLAGS += -fsanitize=address -g
CXX = c++

SRCS =	main.cpp
FLOAT_SRCS = main_T.cpp

OBJS = $(SRCS:.cpp=.o)
FLOAT_OBJS = $(FLOAT_SRCS:.cpp=.o)

all : $(NAME) float

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS)      -o $(NAME) $(OBJS)

run:		all
			./$(NAME)

clean :
	rm -f $(OBJS)
	rm -f $(FLOAT_OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f float_$(NAME)

re : fclean all

float : $(FLOAT_OBJS)
	$(CXX) $(CXXFLAGS)      -o float_$(NAME) $(FLOAT_OBJS)

.PHONY: all clean fclean re
