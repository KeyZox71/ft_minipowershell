/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/06 18:07:24 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include "error_msg.h"
#include <readline/history.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "libft.h"
#include "builtins.h"
#include "minishell.h"
#include "parsing.h"
#include "prompt.h"

void	sig_c(int code)
{
	(void)code;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	main(int ac, char **av, char **env)
{
	char	*rl;
	char	*prompt;
	t_env	env_l;
	t_list	*cmd_list;
	t_list	*piped;

	(void)ac;
	get_program_name(av[0]);
	if (env_init(env, &env_l))
		return (EXIT_FAILURE);
	signal(SIGINT, &sig_c);
	while (1)
	{
		prompt = get_prompt(env_l);
		rl = readline(prompt);
		free(prompt);
		if (!rl)
			exit(727);
		if (!*rl)
			continue ;
		if (check_syntax(rl))
			continue ;
		if (check_quote(rl))
			continue ;
		if (check_pipe(rl))
			continue ;
		piped = tokenizer(rl);
		if (check_argv(piped))
			continue ;
		add_history(rl);
		cmd_list = get_cmd_list(piped, &env_l);
		ft_lstclear(&piped, &free_token);
		format_quotes(cmd_list);
		exec_split_cmd(cmd_list, &env_l);
		ft_lstclear(&cmd_list, &free_cmd);
		free(rl);
	}
	return (0);
}
