/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/16 16:15:38 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

char	**get_rl(char **rl)
{
	static char	**ret;

	if (rl)
		ret = rl;
	return (ret);
}

void	sig_c(int code)
{
	(void)code;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	get_exit_code(0);
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
	if (check_space(rl))
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
	get_env(&env_l);
	if (!env_l)
		return (EXIT_FAILURE);
	get_exit_code(0);
	while (1)
	{
		signal(SIGINT, &sig_c);
		signal(SIGQUIT, SIG_IGN);
		prompt = get_prompt(env_l);
		rl = readline(prompt);
		free(prompt);
		if (!rl)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			get_exit_code(0);
			break ;
		}
		if (run_checks(rl))
		{
			free(rl);
			continue ;
		}
		add_history(rl);
		rl = env_var_replace(rl, env_l);
		printf ("\t%s\n", rl);
		get_rl(&rl);
		piped = tokenizer(rl);
		get_list(&piped);
		if (check_argv(piped))
		{
			free(rl);
			ft_lstclear(&piped, &free_token);
			continue ;
		}
		cmd_list = get_cmd_list(piped);
		free(rl);
		ft_lstclear(&piped, &free_token);
		if (!cmd_list)
			continue ;
		if (format_quotes(cmd_list))
		{
			ft_lstclear(get_list(NULL), &free_cmd);
			continue ;
		}
		get_list(&cmd_list);
		if (check_redir(cmd_list))
		{
			ft_lstclear(get_list(NULL), &free_cmd);
			continue ;
		}
		exec_split_cmd(cmd_list, env_l);
		ft_lstclear(&cmd_list, &free_cmd);
	}
	free(rl);
	rl_clear_history();
	ft_envclear(&env_l, free);
	return (get_exit_code(-1));
}
