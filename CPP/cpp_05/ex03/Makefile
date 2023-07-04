# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnuyten <tnuyten@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 20:18:34 by tnuyten           #+#    #+#              #
#    Updated: 2023/05/04 20:02:07 by tnuyten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := interns
CXXFLAGS =  -Wall -Wextra -Werror -std=c++98
CXX = c++

SRCS =	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		Intern.cpp

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
