# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 17:31:36 by rde-mour          #+#    #+#              #
#    Updated: 2024/11/05 17:43:26 by rde-mour         ###   ########.org.br    #
#                                                                              #
# **************************************************************************** #

RED					= $(shell tput setaf 1)
GREEN				= $(shell tput setaf 2)
YELLOW				= $(shell tput setaf 3)
BLUE				= $(shell tput setaf 4)
MAGENT				= $(shell tput setaf 5)
RESET				= $(shell tput sgr0)

NAME				= fixed

FILES				= Fixed.cpp \
					  Point.cpp \
					  bsp.cpp \
					  main.cpp

OBJS				= $(FILES:%.cpp=%.o)

HEADERS				= -I ./

COMPILER			= c++

CFLAGS				= -Wall -Wextra -Werror -std=c++98


ifdef 				LOG
					LOGGER = -D LOGGER=false
endif

all: 				$(NAME)

$(NAME):			$(OBJS)
					@$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)
					@echo "$(BLUE)Compiled $(NAME) successfully$(RESET)"

%.o: 				%.cpp
					@$(COMPILER) $(CFLAGS) -c $< -o $@ $(HEADERS) $(LOGGER)
					@echo "$(GREEN)Compiled$(RESET) $(notdir $<)"

logger:
					@make LOG=false --no-print-directory

clean:
					@echo "$(RED)Removing$(RESET) $(NAME) objects"
					@rm -rf $(OBJS)

fclean: 			clean
					@echo "$(RED)Removing$(RESET) $(NAME)"
					@rm -rf $(NAME)

re:					fclean all

.PHONY: 			all clean fclean logger re
