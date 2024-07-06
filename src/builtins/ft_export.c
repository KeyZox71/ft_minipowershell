/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:42:36 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/06 18:27:41 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

uint	ft_arraylen(char **s)
{
	char	**endptr;

	endptr = s;
	while (*endptr)
		endptr++;
	return (endptr - s);
}

void	ft_arraysort(char **env)
{
	char	*tmp;
	int		i;
	int		y;

	i = ft_arraylen(env);
	while (i)
	{
		y = 0;
		while (y < i - 1)
		{
			if (ft_strcmp(env[y], env[y + 1]) > 0)
			{
				tmp = env[y];
				env[y] = env[y + 1];
				env[y + 1] = tmp;
			}
			y++;
		}
		i--;
	}
}

void	env_print_in_order(t_env *env_l)
{
	char	**env;
	int		i;

	env = env_get(env_l);
	if (!env)
		return ;
	ft_arraysort(env);
	i = 0;
	while (env[i])
	{
		printf("declare -x %s\n", env[i]);
		i++;
	}
	return ;
}

void	ft_export(char **args, t_env *env)
{
	char	*name;
	char	*content;

	if (!args || !args[0])
	{
		env_print_in_order(env);
		return ;
	}
	while (*args)
	{
		if (!strchr(*args, '='))
			return ;
		name = ft_calloc(sizeof(char), ft_strchr(*args, '=') - *args + 1);
		content = ft_calloc(sizeof(char), ft_strlen(ft_strchr(*args, '=')));
		if (!name || !content)
		{
			ft_free("cc", &name, &content);
			return ;
		}
		ft_strlcpy(name, *args, ft_strchr(*args, '=') - *args + 1);
		ft_strlcpy(content, ft_strchr(*args, '=') + 1,
			ft_strlen(ft_strchr(*args, '=')) + 1);
		if (env_get_value(name, env))
			env_edit(name, content, env);
		else
			ft_envadd_back(&env, ft_envnew(name, content));
		args++;
	}
}
