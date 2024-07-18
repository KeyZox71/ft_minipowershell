/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:19:57 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/18 14:37:39 by mmoussou         ###   ########.fr       */
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
	while (*tmp && (*tmp)[0] == '-' && (*tmp)[1] == 'n')
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

void	ft_echo(char **args, int fd)
{
	char	**tmp;
	bool	new_line;

	fd = STDOUT_FILENO;
	tmp = args;
	if (__nl_option(args) > 0)
		new_line = false;
	else
		new_line = true;
	tmp += __nl_option(args);
	while (*tmp && tmp)
	{
		ft_putstr_fd(*tmp, fd);
		tmp++;
		if (*tmp != NULL)
			ft_putchar_fd(' ', fd);
	}
	if (new_line == true)
		ft_putchar_fd('\n', fd);
}
