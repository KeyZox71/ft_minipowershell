/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/13 16:48:59 by mmoussou         ###   ########.fr       */
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

void	__parse(char *rl, t_env *env_l)
{
	t_list	*token;

	token = tokenizer(rl, env_l);
	if (!token)
		return ;
	get_list(&token);
	exec_split_cmd(token, env_l);
	ft_lstclear(&token, free_cmd);
	return ;
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
