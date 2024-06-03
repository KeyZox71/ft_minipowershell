# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 10:49:52 by adjoly            #+#    #+#              #
#    Updated: 2024/06/03 15:44:04 by mmoussou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

NAME = minishell

CC = cc

OBJSDIR = obj/

SRC = $(shell find src -name '*.c')

I_DIR = include/

LIBFT_DIR = libft/
	   
INCLUDE = -I $(I_DIR) -I $(LIBFT_DIR)/$(I_DIR)

OBJS = $(addprefix $(OBJSDIR), $(SRC:.c=.o))

FLAGS = -Werror -Wall -Wextra -g

LIB = libft/libft.a

# --------------------------------

all: $(NAME)

$(LIB):
	@make -sj$(nproc) -C $(LIBFT_DIR)

$(NAME): $(LIB) $(OBJS)
	@printf "\x1B[2K\r \x1B[1;32m[ 󱌣 ]\x1B[0m objects compiled."
	@printf "\n \x1B[1;33m[  ]\x1B[0m compiling $(NAME)..."
	@$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME) -lreadline
	@printf "\x1B[2K\r \x1B[1;33m[  ]\x1B[0m $(NAME) compiled.\n"

$(OBJSDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDE) $(FLAGS) $< -c -o $@
	@printf "\x1B[2K\r \x1B[1;32m[ 󱌣 ]\x1B[0m compiling objects... : $<"

clean:
	@make -s -C libft clean
	@rm -f $(OBJS)
	@printf " \x1B[1;31m[  ]\x1B[0m deleted $(NAME).\n"

fclean: clean
	@make -s -C libft fclean
	@rm -f $(NAME)
	@rm -Rf $(OBJSDIR)
	@printf " \x1B[1;31m[  ]\x1B[0m deleted objects.\n"

re: fclean all

.PHONY: clean all re fclean
