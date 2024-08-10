/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:48:57 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/10 17:54:35 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdio.h>

size_t	__get_len_arg(char *s)
{
	char	*tmp;

	tmp = s;
	if (ft_ischevron(*tmp))
	{
		while (*tmp && ft_ischevron(*tmp))
			tmp++;
		return (tmp - s);
	}
	while (tmp && *tmp)
	{
		if ((ft_isspace(*tmp) || ft_ischevron(*tmp)) \
				&& is_inquote(s, tmp - s) == FALSE)
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
		if (ft_isspace(*tmp))
			tmp++;
		else
		{
			tmp += __get_len_arg(tmp);
			i++;
		}
	}
	return (i);
}

char	**__split_argv(char *tmp)
{
	char	**argv;
	char	**tmp_av;

	argv = ft_calloc(__count_args(tmp) + 1, sizeof(char *));
	tmp_av = argv;
	while (*tmp)
	{
		if (ft_isspace(*tmp))
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

char	**split_argv(char *readline)
{
	char	**argv;
	char	*tmp;

	if (!readline)
		return (NULL);
	if (!*readline)
	{
		free(readline);
		return (NULL);
	}
	tmp = readline;
	argv = __split_argv(tmp);
	free(readline);
	return (argv);
}
