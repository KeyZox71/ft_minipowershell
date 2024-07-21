/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/21 13:09:17 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

int	free_end(char *rl, t_env *env_l, int exit_code, bool print)
{
	free(rl);
	rl_clear_history();
	ft_envclear(&env_l, free);
	if (print == true)
		ft_putendl_fd("exit", STDOUT_FILENO);
	return (get_exit_code(exit_code));
}

void	__exec(t_list *cmd_list, t_env *env_l)
{
	if (!cmd_list)
		return ;
	if (format_quotes(cmd_list))
	{
		ft_lstclear(get_list(NULL), &free_cmd);
		return ;
	}
	get_list(&cmd_list);
	if (check_redir(cmd_list))
	{
		ft_lstclear(get_list(NULL), &free_cmd);
		return ;
	}
	exec_split_cmd(cmd_list, env_l);
	ft_lstclear(&cmd_list, &free_cmd);
}

void	__parse(char *rl, t_env *env_l)
{
	t_list	*cmd_list;
	t_list	*piped;

	rl = env_var_replace(rl, env_l);
	get_rl(&rl);
	piped = tokenizer(rl);
	get_list(&piped);
	if (check_argv(piped))
	{
		free(rl);
		ft_lstclear(&piped, &free_token);
		return ;
	}
	cmd_list = get_cmd_list(piped);
	free(rl);
	ft_lstclear(&piped, &free_token);
	__exec(cmd_list, env_l);
}

char	*__rl(t_env *env_l)
{
	char	*rl;
	char	*prompt;

	signal(SIGINT, &sig_c);
	signal(SIGQUIT, SIG_IGN);
	prompt = get_prompt(env_l);
	rl = readline(prompt);
	free(prompt);
	return (rl);
}

int	main(int ac, char **av, char **env)
{
	char	*rl;
	t_env	*env_l;

	(void)ac;
	get_program_name(av[0]);
	env_l = env_init(env);
	if (!env_l)
		return (EXIT_FAILURE);
	get_env(&env_l);
	get_exit_code(0);
	while (1)
	{
		rl = __rl(env_l);
		if (!rl)
			return (free_end(rl, env_l, -1, true));
		if (run_checks(rl))
		{
			free(rl);
			continue ;
		}
		__parse(rl, env_l);
	}
	return (free_end(rl, env_l, -1, false));
}
