# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duamarqu <duamarqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 17:19:06 by duamarqu          #+#    #+#              #
#    Updated: 2023/11/03 15:12:06 by duamarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
CC= cc
CFLAGS= -Wall -Wextra -Werror
SRC= ft_printf.c ft_printf_fuctions.c
OBJ= $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
