/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/09 16:41:08 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_c(int code)
{
	(void)code;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

bool	run_checks(char *rl)
{
	if (!*rl)
		return (true);
	if (check_syntax(rl))
		return (true);
	if (check_quote(rl))
		return (true);
	if (check_pipe(rl))
		return (true);
	return (false);
}

int	main(int ac, char **av, char **env)
{
	char	*rl;
	char	*prompt;
	t_env	*env_l;
	t_list	*cmd_list;
	t_list	*piped;

	(void)ac;
	rl = NULL;
	get_program_name(av[0]);
	env_l = env_init(env);
	if (!env_l)
		return (EXIT_FAILURE);
	signal(SIGINT, &sig_c);
	while (1)
	{
		prompt = get_prompt(env_l);
		rl = readline(prompt);
		free(prompt);
		if (!rl)
			break ;
		if (run_checks(rl))
		{
			free(rl);
			continue ;
		}
		piped = tokenizer(rl);
		if (check_argv(piped))
			continue ;
		add_history(rl);
		cmd_list = get_cmd_list(piped, env_l);
		free(rl);
		ft_lstclear(&piped, &free_token);
		format_quotes(cmd_list);
		if (check_redir(cmd_list))
		{
			ft_lstclear(&cmd_list, &free_cmd);
			continue ;
		}
		exec_split_cmd(cmd_list, env_l);
		ft_lstclear(&cmd_list, &free_cmd);
	}
	free(rl);
	rl_clear_history();
	ft_envclear(&env_l, free);
	return (727);
}
