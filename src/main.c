/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/27 17:34:52 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_boolean	is_str(char *src, char *dst)
{
	while (*src && *dst && *src == *dst)
	{
		src++;
		dst++;
	}
	if (*src)
		return (FALSE);
	return (TRUE);
}

void	get_prompt(void)
{
	char	*pwd;
	char	*home;
	char	*user;
	char	*host;

	pwd = getenv("PWD");
	home = getenv("HOME");
	host = getenv("HOST");
	user = getenv("USER");

	if (!ft_strncmp(pwd, home, ft_strlen(home)))
	{
		ft_printf("%s@%s:~%s> ", user, host, pwd + ft_strlen(home));
		return ;
	}
	ft_printf("%s@%s:%s> ", user, host, pwd);
}

int	main(int ac, char **av, char **env)
{
	char	*test;
	char	**lll;

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		get_prompt();
		test = readline(NULL);
		lll = ft_split(test, ' ');
		if (!*lll)
			continue;
		if (is_str(test, "exit"))
			break;
	}
	ft_freearr((void **)lll);
	return (0);
}
