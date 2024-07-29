# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 10:49:52 by adjoly            #+#    #+#              #
#    Updated: 2024/07/29 19:26:36 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

NAME = minishell

CC = cc

OBJSDIR = obj/

SRC = src/utils/free_list.c \
		src/utils/sig.c \
		src/utils/ft_arrlen.c \
		src/utils/get.c \
		src/utils/ret_cwd.c \
		src/utils/get_to_free.c \
		src/utils/is_str.c \
		src/builtins/ft_echo.c \
		src/builtins/free_exit.c \
		src/builtins/ft_export_utils2.c \
		src/builtins/ft_cd.c \
		src/builtins/ft_unset.c \
		src/builtins/ft_env.c \
		src/builtins/ft_pwd.c \
		src/builtins/ft_exit.c \
		src/builtins/ft_export.c \
		src/builtins/ft_export_utils.c \
		src/env/env_cmd.c \
		src/env/env_list/ft_envnew.c \
		src/env/env_list/ft_envprint.c \
		src/env/env_list/ft_envadd_back.c \
		src/env/env_list/ft_envsize.c \
		src/env/env_list/ft_envdelone.c \
		src/env/env_list/ft_envadd_front.c \
		src/env/env_list/ft_envlast.c \
		src/env/env_list/ft_envclear.c \
		src/env/env_setters.c \
		src/main.c \
		src/prompt/get_pwd.c \
		src/prompt/get_prompt.c \
		src/prompt/get_hostname.c \
		src/exec/sig.c \
		src/exec/format_quotes.c \
		src/exec/heredoc_utils.c \
		src/exec/free_exec.c \
		src/exec/exec_cmd.c \
		src/exec/exec_split_cmd.c \
		src/exec/utils_exec_2.c \
		src/exec/utils_exec.c \
		src/exec/heredoc.c \
		src/exec/get_path.c \
		src/parsing/is_inquote.c \
		src/parsing/get_redir_fd.c \
		src/parsing/split_cmd.c \
		src/parsing/is_quote.c \
		src/parsing/open_redir.c \
		src/parsing/tokenizer/__to_redir_sign.c \
		src/parsing/tokenizer/__split_pipe.c \
		src/parsing/tokenizer/__to_token.c \
		src/parsing/tokenizer/__to_redir.c \
		src/parsing/tokenizer/tokenizer.c \
		src/parsing/check_error/run_checks.c \
		src/parsing/check_error/check_redir.c \
		src/parsing/check_error/check_wspace.c \
		src/parsing/check_error/check_argv.c \
		src/parsing/check_error/check_syntax.c \
		src/parsing/check_error/send_error.c \
		src/parsing/check_error/check_pipe.c \
		src/parsing/check_error/check_quote.c \
		src/parsing/get_cmd_list.c \
		src/parsing/env_var/env_var_replace.c \
		src/parsing/env_var/strlen_till_char.c \
		src/parsing/env_var/get_size_with_env.c \
		src/parsing/split_argv.c

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
