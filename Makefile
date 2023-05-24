# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 11:25:07 by iganiev           #+#    #+#              #
#    Updated: 2023/05/23 11:29:00 by iganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = cd libft && make

MYPRINTF = cd printf42 && make

$(NAME): $(OBJ)
		$(LIB)
		$(MYPRINTF)
		gcc $(OBJ)  libft/libft.a printf42/libftprintf.a -o $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJ)
		cd libft && make clean
		cd printf42 && make clean
fclean: clean
		rm -f $(NAME)
		cd libft && make fclean
		cd printf42 && make fclean
re:		fclean all
		cd libft && make fclean && make all
		cd printf42 && make fclean && make all

.PHONY:	all clean fclean re