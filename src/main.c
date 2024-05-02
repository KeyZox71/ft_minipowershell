/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/02 15:47:34 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "minishell.h"

bool	is_str(char *src, char *dst)
{
	while (*src && *dst && *src == *dst)
	{
		src++;
		dst++;
	}
	if (*dst)
		return (false);
	return (true);
}

int	main(int ac, char **av, char **env)
{
	char	*test;
	char	**lll;
	char	*prompt;

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		prompt = get_prompt();
		test = readline(prompt);
		add_history(test);
		lll = ft_split(test, ' ');
		if (!*lll)
			continue;
		if (is_str(test, "exit"))
			break;
	}
	//ft_free("a", &lll);
	return (0);
}
