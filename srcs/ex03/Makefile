# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpedroso <fpedroso@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/01 16:16:02 by fpedroso          #+#    #+#              #
#    Updated: 2026/11/01 16:16:02 by fpedroso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = main.cpp					\
		Bureaucrat.cpp				\
		AForm.cpp					\
		PresidentialPardonForm.cpp	\
		RobotomyRequestForm.cpp		\
		ShrubberyCreationForm.cpp	\
		Intern.cpp

OBJ = $(FILES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)


all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
