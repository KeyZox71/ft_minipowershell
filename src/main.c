/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/25 11:30:17 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdio.h>
#include "libft.h"

t_boolean	is_str(char *src, char *dst)
{
	while (*src++ == *dst++)
		;
	if (*src)
		return (FALSE);
	return (TRUE);
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
		test = readline("test>");
		lll = ft_split(test, ' ');
		if (is_str(*lll, "exit") == TRUE)
			return (0);
		if (is_str(*lll, "uwu") == TRUE)
		{
			printf("go burn in hell\n");
			return (0);
		}
		printf("%s\n", test);
	}
	return (0);
}
