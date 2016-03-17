# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: droly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 16:34:45 by droly             #+#    #+#              #
#    Updated: 2016/03/17 16:44:57 by droly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = algo.c \
	  functions.c \
	  push_swap.c

OBJ = $(SRC:.c=.o)

HEAD = push_swap.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) makelibft
	@clang $(FLAGS) -c $(SRC) -I$(HEAD)
	@clang $(OBJ) libft/libft.a -o $(NAME)

makelibft:
	@make -C libft/
	@echo "Library included."

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "Target cleaned."

re: fclean all

.PHONY: all makelibft clean fclean re
