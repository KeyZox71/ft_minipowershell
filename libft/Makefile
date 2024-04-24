# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 11:03:22 by adjoly            #+#    #+#              #
#    Updated: 2024/03/18 14:33:40 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

OBJSDIR = obj/

SRCS = is/ft_isalnum.c \
		is/ft_isalpha.c \
		is/ft_isascii.c \
		is/ft_isdigit.c \
		is/ft_isprint.c \
		lst/ft_lstadd_back.c \
		lst/ft_lstadd_front.c \
		lst/ft_lstclear.c \
		lst/ft_lstdelone.c \
		lst/ft_lstiter.c \
		lst/ft_lstlast.c \
		lst/ft_lstmap.c \
		lst/ft_lstnew.c \
		lst/ft_lstsize.c \
		mem/ft_bzero.c \
		mem/ft_calloc.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memmove.c \
		mem/ft_memset.c \
		print/ft_putchar.c \
		print/ft_putchar_fd.c \
		print/ft_putendl_fd.c \
		print/ft_putnbrbase.c \
		print/ft_putnbrbase_fd.c \
		print/ft_putnbr.c \
		print/ft_putnbr_fd.c \
		print/ft_putstr.c \
		print/ft_putstr_fd.c \
		str/ft_atoi.c \
		str/ft_atoll.c \
		str/ft_itoa.c \
		str/ft_split.c \
		str/ft_strchr.c \
		str/ft_strdup.c \
		str/ft_striteri.c \
		str/ft_strjoin.c \
		str/ft_strlcat.c \
		str/ft_strlcpy.c \
		str/ft_strlen.c \
		str/ft_strmapi.c \
		str/ft_strncmp.c \
		str/ft_strnstr.c \
		str/ft_strrchr.c \
		str/ft_strtrim.c \
		str/ft_substr.c \
		str/ft_tolower.c \
		str/ft_toupper.c \
		print/printf/ft_printf.c \
		print/printf/ft_putchar.c \
		print/printf/ft_putnbrbase.c \
		print/printf/ft_putnbr.c \
		print/printf/ft_putstr.c \

OBJS = $(addprefix $(OBJSDIR),$(SRCS:.c=.o))

FLAGS = -Werror -Wall -Wextra -g

LIB = io/get_next_line/get_next_line.a

$(NAME): $(OBJS)
	@make -s -C io/get_next_line/
	@ar -rcs	$(NAME) $(OBJS) $(LIB)
	@echo "[✔] Libft compiled"

$(OBJSDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $< -c -o $@

all: $(NAME)

clean:
	@make -s -C io/get_next_line/ clean
	@rm -f $(OBJS)

fclean: clean
	@make -s -C io/get_next_line/ fclean
	@rm -f $(NAME)
	@echo "[X] Libft cleaned"

re: fclean all

.PHONY: clean all re fclean
