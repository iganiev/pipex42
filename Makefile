# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 11:25:07 by iganiev           #+#    #+#              #
#    Updated: 2023/05/31 16:43:02 by iganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c find_path.c process.c utils.c \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3 
#-fsanitize=address

LIB = cd libft && make

$(NAME): $(OBJ)
		$(LIB)
		gcc $(OBJ)  $(CFLAGS) libft/libft.a -o $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJ)
		cd libft && make clean

fclean: clean
		rm -f $(NAME)
		cd libft && make fclean

re:		fclean all
		cd libft && make fclean && make all

.PHONY:	all clean fclean re