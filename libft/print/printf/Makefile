# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 12:35:27 by adjoly            #+#    #+#              #
#    Updated: 2024/02/04 15:18:46 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

SRCS = ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putnbrbase.c \
		ft_putstr.c \
		../../str/ft_strlen.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wall -Wextra

HEADER = libftprintf.h 

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEADER) $< -c -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
