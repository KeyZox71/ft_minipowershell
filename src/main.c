/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/09 18:05:14 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "libft.h"
#include "minishell.h"
#include "parsing.h"

void	print_cmd(t_cmd cmd)
{
	ft_putendl_fd(cmd.cmd, 1);	
	while (*(cmd.argv))
	{
		ft_putendl_fd(*(cmd.argv), 1);
		(cmd.argv)++;
	}
}

void	print_pipe(t_list *pipe)
{
	t_list	*tmp;

	tmp = pipe;
	if (!pipe->next)
	{
		print_cmd(*(t_cmd*)tmp->content);
		return;
	}
	while (tmp) 
	{
		print_cmd(*(t_cmd*)tmp->content);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*test;
	char	**lll;
	char	*prompt;
	t_list	*cmd;

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		prompt = get_prompt();
		test = readline(prompt);
		free(prompt);
		add_history(test);
		lll = ft_split(test, ' ');
		if (!*lll)
			continue;
		if (is_str(test, "exit"))
			break;
		cmd = split_pipe(test);
		print_pipe(cmd);
		ft_free("a", &lll);
	}
	ft_free("a", &lll);
	return (0);
}
