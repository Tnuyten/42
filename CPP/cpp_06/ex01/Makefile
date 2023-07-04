# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 20:18:34 by tnuyten           #+#    #+#              #
#    Updated: 2023/05/24 11:55:47 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := serialize
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g -pedantic
CXX = c++

SRCS =	main.cpp \
		Serializer.cpp \
		Data.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o: %.cpp
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
