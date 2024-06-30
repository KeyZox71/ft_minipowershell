/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/30 17:28:28 by adjoly           ###   ########.fr       */
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

void	free_redir(void *redir_v)
{
	t_redirection	*redir;

	redir = redir_v;
	free(redir->file_name);
}

void	free_token(void *token_v)
{
	t_token	*token;

	token = token_v;
	free(token->argv);
	ft_lstclear(&(token->redirection), free_redir);
}

/*void	print_cmd(t_cmd cmd)
{
	ft_putendl_fd(cmd.cmd, 1);	
	while (*(cmd.argv))
	{
		ft_putendl_fd(*(cmd.argv), 1);
		(cmd.argv)++;
	}
}*/

void	print_pipe(t_list *pipe)
{
	t_list	*tmp;

	tmp = pipe;
	while (tmp)
	{
		ft_putendl_fd(tmp->content, STDOUT_FILENO);
		tmp = tmp->next;
	}
}

void	sigggg(int code)
{
	(void)code;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	siggg_backslash(int code)
{
	(void)code;
	rl_replace_line("", 0);
	rl_redisplay();
}

void	siggg_d(int code)
{
	(void)code;
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	char	*test;
	char	*prompt;
	char	**lll;
	t_list	*piped;
	t_env	env_l;
	t_list	*cmd_list;

	(void)ac;
	(void)av;
	get_program_name(av[0]);
	piped = NULL;
	if (env_init(env, &env_l))
		return (EXIT_FAILURE);
	sigemptyset(&(sigset_t){SIGQUIT});
	signal(SIGINT, &sigggg);
	signal(SIGQUIT, &siggg_backslash);
	//signal(SIGSEGV, &siggg_d);
	while (1)
	{
		prompt = get_prompt(env_l);
		test = readline(prompt);
		free(prompt);
		add_history(test);
		if (check_syntax(test))
			continue ;
		lll = ft_split(test, ' ');
		if (!*lll)
			continue ;
		else if (is_str(test, "pwd"))
		{
			ft_pwd();
			continue ;
		}
		else if (is_str(test, "export"))
		{
			ft_export(NULL, &env_l);
			continue ;
		}
		else if (is_str(test, "cd"))
		{
			ft_cd(&env_l, lll[1]);
			continue ;
		}
		else if (is_str(test, "echo"))
		{
			ft_echo(lll + 1);
			continue ;
		}
		else if (is_str(test, "exit"))
			exit(EXIT_SUCCESS);
		if (check_quote(test))
			continue ;
		if (check_pipe(test))
			continue ;
		piped = tokenizer(test);
		if (check_redir(((t_token *)(piped->content))->redirection))
			continue ;
		cmd_list = get_cmd_list(piped);
		exec_split_cmd(cmd_list, &env_l);
		free(test);
		ft_lstclear(&piped, free_token);
		ft_free("a", &lll);
	}
	ft_free("a", &lll);
	return (0);
}
