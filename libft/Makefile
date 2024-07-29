# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 07:21:18 by mmoussou          #+#    #+#              #
#    Updated: 2024/07/29 19:27:29 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

CC = cc

CFLAGS = -Wall -Werror -Wextra -pipe -fPIE

INCLUDE = ./include

NAME = libft.a

#find -type f -name "*.c" | sed "s/\.\///g" | xargs -Iname echo "`printf '\t\t\t'`" name "\\"
SRCS = 		 src/io/ft_putnbr_fd.c \
			 src/io/ft_putuhex_fd.c \
			 src/io/ft_putendl_fd.c \
			 src/io/ft_putstr_fd.c \
			 src/io/ft_printf.c \
			 src/io/ft_printf_fd.c \
			 src/io/ft_putchar_fd.c \
			 src/io/get_next_line/get_next_line.c \
			 \
			 src/int/ft_min.c \
			 src/int/ft_max.c \
			 src/int/ft_abs.c \
			 \
			 src/mem/ft_memchr.c \
			 src/mem/ft_calloc.c \
			 src/mem/ft_memcpy.c \
			 src/mem/ft_free.c \
			 src/mem/ft_memset.c \
			 src/mem/ft_memcmp.c \
			 src/mem/ft_memmove.c \
			 src/mem/ft_bzero.c \
			 \
			 src/str/XtoX/ft_atol.c \
			 src/str/XtoX/ft_itoa.c \
			 src/str/XtoX/ft_atoi.c \
			 src/str/XtoX/ft_ltoa.c \
			 \
			 src/str/ft_strchr.c \
			 src/str/ft_strtrim.c \
			 src/str/ft_strcmp.c \
			 src/str/ft_striteri.c \
			 src/str/ft_strmapi.c \
			 src/str/ft_substr.c \
			 src/str/ft_strdup.c \
			 src/str/ft_strnstr.c \
			 src/str/ft_tolower.c \
			 src/str/ft_strlcpy.c \
			 src/str/ft_strlen.c \
			 src/str/ft_strjoin.c \
			 src/str/ft_strncmp.c \
			 src/str/ft_strrchr.c \
			 src/str/ft_split.c \
			 src/str/ft_strlcat.c \
			 src/str/ft_toupper.c \
			 \
			 src/char/ft_isdigit.c \
			 src/char/ft_isalnum.c \
			 src/char/ft_isprint.c \
			 src/char/ft_isalpha.c \
			 src/char/ft_isascii.c \
			 src/char/ft_isspace.c \
			 \
			 src/stack/ft_stackadd_front.c \
			 src/stack/ft_stackadd_back.c \
			 src/stack/ft_stacksize.c \
			 src/stack/ft_stacknew.c \
			 src/stack/ft_stacklast.c \
			 \
			 src/linked_lists/ft_lstmap.c \
			 src/linked_lists/ft_lstnew.c \
			 src/linked_lists/ft_lstclear.c \
			 src/linked_lists/ft_lstsize.c \
			 src/linked_lists/ft_lstadd_front.c \
			 src/linked_lists/ft_lstadd_back.c \
			 src/linked_lists/ft_lstiter.c \
			 src/linked_lists/ft_lstlast.c \
			 src/linked_lists/ft_lstdelone.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

%.o: %.c
	@printf "\x1B[2K\r \x1B[1;32m[ 󱌣 ]\x1B[0m compiling libft objects... : $<"
	@$(CC) $(CFLAGS) -I$(INCLUDE) $< -c -o $@

$(NAME): $(OBJS)
	@printf "\x1B[2K\r \x1B[1;32m[ 󱌣 ]\x1B[0m libft objects compiled."
	@printf "\n \x1B[1;33m[ 󱉟 ]\x1B[0m creating libft archive..."
	@ar rcs $(NAME) $(OBJS)
	@printf "\x1B[2K\r \x1B[1;33m[ 󱉟 ]\x1B[0m libft archive created.\n"

clean: 
	@rm -f $(OBJS)
	@printf " \x1B[1;31m[  ]\x1B[0m deleted libft objects.\n"

fclean: clean
	@rm -f $(NAME)
	@printf " \x1B[1;31m[  ]\x1B[0m deleted libft archive.\n"

re: fclean all

.PHONY: all clean fclean re
