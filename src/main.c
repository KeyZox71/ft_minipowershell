/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/25 17:53:36 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
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
	piped = NULL;
	if (env_init(env, &env_l))
		return (EXIT_FAILURE);
	signal(SIGINT, &sigggg);
	while (1)
	{
		prompt = get_prompt(env_l);
		test = readline(prompt);
		free(prompt);
		add_history(test);
		check_syntax(test, av);
		lll = ft_split(test, ' ');
		if (!*lll)
			continue ;
		if (is_str(test, "exit"))
			break ;
		if (is_str(test, "pwd"))
		{
			ft_pwd();
			continue ;
		}
		if (is_str(test, "cd"))
		{
			ft_cd(&env_l, lll[1]);
			continue ;
		}
		check_quote(test);
		piped = tokenizer(test);
		//check_redir(((t_token *)(piped->content))->redirection, av);
		cmd_list = get_cmd_list(piped, &env_l);
		exec_split_cmd(cmd_list, &env_l);
		free(test);
		ft_lstclear(&piped, free_token);
		ft_free("a", &lll);
	}
	ft_free("a", &lll);
	return (0);
}
