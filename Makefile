# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 19:27:37 by albzamor          #+#    #+#              #
#    Updated: 2021/07/06 17:17:11 by albzamor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= 	f_

SRC_BONUS	= get_next_line.h

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_BONUS:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?
bonus: $(OBJ_B)
	ar rcs $(NAME) $?

clean:
	rm -f $(OBJ) $(OBJ_B)
fclean: clean
	rm -f $(NAME)
re: fclean all bonus
.PHONY: all bonus clean fclean re
