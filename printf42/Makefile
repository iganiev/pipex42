# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iganiev <iganiev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 18:26:55 by iganiev           #+#    #+#              #
#    Updated: 2023/01/30 18:26:57 by iganiev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c print_char.c print_str.c \
		print_int.c print_unint.c print_hex.c \
		print_pointer.c \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar -rcs

RM = rm -f

CL = clean

CLA = fclean all

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: $(CL)
	@$(RM) $(NAME) 

re: $(CLA)

.PHONY: all clean fclean re