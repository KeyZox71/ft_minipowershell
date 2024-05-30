/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/30 16:37:57 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "libft.h"
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

int	main(int ac, char **av, char **env)
{
	//ft_heredoc("EOF");
	char	*test;
	char	*prompt;
	char	**lll;
	t_list	*piped;
	t_env	env_l;
	t_cmd	*cmd;
	//t_token	*token;

	(void)ac;
	(void)av;
	(void)env;
	piped = NULL;
	if (env_init(env, &env_l))
		return (EXIT_FAILURE);
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
		piped = tokenizer(test);
//		check_redir(((t_token *)(piped->content))->redirection, av);
/*		while (piped)
		{
			print_token(piped->content);
			piped = piped->next;
		}*/
		cmd = get_redir_fd(piped->content);
		print_cmd(cmd);
		free(test);
		ft_lstclear(&piped, free_token);
		ft_free("a", &lll);
	}
	ft_free("a", &lll);
	return (0);
}

/*int	main()
{
	char	*ll = "asdf\"xf\"asfffd";
	t_quote	d;

	d = is_inquote(ll, 6);
	ft_printf("%c\n", *(ll+6));
	print_quote_type(d);
}*/
