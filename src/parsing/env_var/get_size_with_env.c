/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_with_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:01:19 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/24 12:51:59 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env.h"
#include "parsing.h"
#include "libft.h"

size_t	get_size_with_env(char *readline, t_env *env)
{
	size_t	size;
	char	*tmp;
	char	*dollar;

	tmp = readline;
	size = ft_strlen(readline);
	while (*tmp)
	{
		if (*tmp == '$' && is_inquote(tmp, tmp - readline) != SINGLE && \
				is_inquote(tmp, tmp - readline) != NOT_CLOSED)
		{
			tmp++;
			size -= strlen_till_char(tmp, ' ');
			dollar = env_getn_value(tmp, env, strlen_till_char(tmp, ' '));
			if (!dollar)
				continue ;
			size += ft_strlen(dollar);
		}
		tmp++;
	}
	return (size);
}
