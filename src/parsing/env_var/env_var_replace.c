/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:14:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/13 17:21:59 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"
#include "minishell.h"
#include "env.h"

void	__cpy_dollar(char *tmp, size_t dollar_size, t_env *env, char **rl_dlrd)
{
	char	*dollar;

	dollar = env_getn_value(tmp, env, dollar_size - 1);
	if (!dollar)
	{
		tmp += dollar_size;
		return ;
	}
	ft_strlcat(*rl_dlrd, dollar, \
			ft_strlen(dollar) + ft_strlen(*rl_dlrd) + 1);
}

size_t	strlen_till_notalnum(char *s)
{
	char	*tmp;

	tmp = s;
	while (*tmp && ft_isalnum(*tmp))
		tmp++;
	return (tmp - s);
}

size_t __add_dollar(t_env *env, char **rl_dollared, char *tmp)
{
	size_t	dollar_size;

	tmp++;
	if ((*tmp) == '?')
	{
		ft_strlcat(*rl_dollared, ft_itoa(get_exit_code(-1)), \
			 ft_strlen(ft_itoa(get_exit_code(-1))) \
			 + ft_strlen(*rl_dollared) + 1);
		return (1);
	}
	dollar_size = strlen_till_notalnum(tmp);
	__cpy_dollar(tmp, dollar_size, env, rl_dollared);
	return (dollar_size);
}

char	*env_var_replace(char *readline, t_env *env)
{
	char	*tmp;
	char	*rl_dollared;

	rl_dollared = ft_calloc(get_size_with_env(readline, env) + 1, sizeof(char));
	if (rl_dollared == NULL)
		return (NULL);
	tmp = readline;
	while (*tmp)
	{
		if (*tmp == '$' && is_inquote(readline, tmp - readline) != SINGLE)
			tmp += __add_dollar(env, &rl_dollared, tmp) + 1;
		else
		{
			ft_strlcat(rl_dollared, tmp, ft_strlen(rl_dollared) + 2);
			tmp++;
		}
	}
	free(readline);
	return (rl_dollared);
}
