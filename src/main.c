/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/30 12:40:35 by adjoly           ###   ########.fr       */
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

/*char	*get_hostname(void)
{
	char	*hostname;
	char	*tmp;
	int		host_file;

	//host_file = open();
	tmp = hostname;
	while (*tmp)
		tmp++;
	return
}*/

char	*get_prompt(void)
{
	char	**prompt;
	char	*ret = NULL;
	char	*home;
	char	**tmp;

	prompt = malloc(1000);
	prompt[0] = getenv("USER");
	prompt[1] = "@";
	//prompt[2] = get_hostname();
	home = getenv("HOME");
	prompt[3] = getenv("PWD");
	prompt[4] = ">";
	//ret = ft_calloc(1000, sizeof(char));

	if (!ft_strncmp(prompt[3], home, ft_strlen(home)))
		prompt[3] += ft_strlen(home);
	tmp = prompt;
	while (*tmp)
	{
		ft_strlcat(ret, *tmp, ft_strlen(ret) + ft_strlen(*tmp) + 1);
		tmp++;
	}
	free(prompt);
	return (ret);
}

int	main(int ac, char **av, char **env)
{
	char	*test;
	char	**lll;
	char	*ret = NULL;

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		ret = get_prompt();
		test = readline(ret);
		free(ret);
		add_history(test);
		lll = ft_split(test, ' ');
		if (!*lll)
			continue;
		if (is_str(test, "exit"))
			break;
	}
	//ft_freearr((void **)lll);
	return (0);
}
