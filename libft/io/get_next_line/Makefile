# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 11:03:22 by adjoly            #+#    #+#              #
#    Updated: 2024/03/04 13:30:36 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = clang

SRCS = get_next_line.c \
		get_next_line_utils.c \
		../../mem/ft_calloc.c \
		../../str/ft_strlen.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wall -Wextra

HEADER = get_next_line.h

$(NAME): $(OBJS)
	@ar -rcs	$(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(FLAGS) -I $(HEADER) $< -c -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
