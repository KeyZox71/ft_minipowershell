/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/04 15:33:54 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "minishell.h"

void	print_cmd(t_cmd cmd)
{
	ft_putendl_fd(cmd.cmd, 1);	
	while (*(cmd.argv))
	{
		ft_putendl_fd(*(cmd.argv), 1);
		(cmd.argv)++;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*test;
	char	**lll;
	char	*prompt;
	t_cmd	*cmd;

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
		cmd = ft_calloc(sizeof(t_cmd), 1);
		*cmd = split_cmd(test);
		print_cmd(*cmd);
		ft_free("a", &lll);
	}
	ft_free("a", &lll);
	return (0);
}
