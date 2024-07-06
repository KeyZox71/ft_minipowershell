/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:48:57 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/06 15:04:35 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdio.h>

size_t	__get_len_arg(char *s)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
	{
		if (*tmp == ' ' && is_inquote(s, tmp - s) == FALSE)
			break ;
		tmp++;
	}
	return (tmp - s);
}

size_t	__cpy_arg(char *dst, char *src)
{
	size_t	sizeof_arg;

	sizeof_arg = __get_len_arg(src);
	ft_strlcpy(dst, src, sizeof_arg + 1);
	return (sizeof_arg);
}

size_t	__count_args(char *s)
{
	size_t	i;
	char	*tmp;

	tmp = s;
	i = 0;
	while (*tmp)
	{
		if (*tmp == ' ')
			tmp++;
		else
		{
			tmp += __get_len_arg(tmp);
			i++;
		}
	}
	return (i);
}

char	**split_argv(char *readline)
{
	char	**argv;
	char	**tmp_av;
	char	*tmp;

	tmp = readline;
	argv = ft_calloc(__count_args(readline) + 1, sizeof(char *));
	tmp_av = argv;
	while (*tmp)
	{
		if (*tmp == ' ')
			tmp++;
		else
		{
			*tmp_av = ft_calloc(__get_len_arg(tmp) + 1, sizeof(char));
			tmp += __cpy_arg(*tmp_av, tmp);
			tmp_av++;
		}
	}
	*tmp_av = NULL;
	return (argv);
}
