# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 20:18:34 by tnuyten           #+#    #+#              #
#    Updated: 2023/05/11 21:09:38 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := convert
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98
CXX = c++

SRCS =	main.cpp \
		ScalarConverter.cpp \

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

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
