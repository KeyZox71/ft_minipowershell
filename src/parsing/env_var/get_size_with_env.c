/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_with_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:01:19 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/21 15:40:01 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "parsing.h"
#include "libft.h"

#include <stdio.h>

size_t	__add_sizeof_dollar(size_t size, char **tmp, t_env *env, char *readline)
{
	char	*dollar;

	if (**tmp == '$' && *(*tmp + 1) == '?' && \
		is_inquote(*tmp, *tmp - readline) != SINGLE && \
		is_inquote(*tmp, *tmp - readline) != NOT_CLOSED)
	{
		*tmp += 2;
		size++;
	}
	else if (**tmp == '$' && is_inquote(*tmp, *tmp - readline) != SINGLE)
	{
		(*tmp)++;
		size -= strlen_till_notalnum(*tmp);
		dollar = env_getn_value(*tmp, env, strlen_till_notalnum(*tmp) - 1);
		if (!dollar)
			return (size);
		size += ft_strlen(dollar);
		free(dollar);
	}
	return (size);
}

size_t	get_size_with_env(char *readline, t_env *env)
{
	size_t	size;
	char	*tmp;

	tmp = readline;
	size = ft_strlen(readline);
	while (*tmp)
	{
		size = __add_sizeof_dollar(size, &tmp, env, readline);
		if (!*tmp)
			break ;
		tmp++;
	}
	return (size + 1);
}
