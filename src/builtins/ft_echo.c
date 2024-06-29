/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:19:57 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/29 20:04:36 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
//#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

size_t	__nl_option(char **args)
{
	char	**tmp;
	char	*tmp_arg;
	size_t	i;

	tmp = args;
	i = 0;
	while ((*tmp)[0] == '-' && (*tmp)[1] == 'n')
	{
		tmp_arg = (*tmp);
		tmp_arg++;
		while (*tmp_arg == 'n')
			tmp_arg++;
		if (*tmp_arg)
			break ;
		i++;
		tmp++;
	}
	return (i);
}

void	ft_echo(char **args)
{
	char	**tmp;
	bool	new_line;

	tmp = args;
	if (__nl_option(args) > 0)
		new_line = false;
	else
		new_line = true;
	tmp += __nl_option(args);
	while (*tmp)
	{
		ft_putstr_fd(*tmp, STDOUT_FILENO);
		tmp++;
		if (*tmp != NULL)
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (new_line == true)
		ft_putchar_fd('\n', STDOUT_FILENO);
}
