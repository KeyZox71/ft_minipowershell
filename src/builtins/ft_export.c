/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:42:36 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/26 10:21:18 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_print_in_order(t_env *env_l)
{
	char	**env;

	env = env_get(env_l);
	if (!env)
		return ;
	// sort env
	// printf("declare -x %s\n", env[i]);
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
		name = ft_calloc(sizeof(char), ft_strchr(*args, '=') - *args + 1);
		content = ft_calloc(sizeof(char), ft_strlen(ft_strchr(*args, '=')));
		if (!name || !content)
		{
			ft_free("cc", &name, &content);
			return ;
		}
		ft_strlcpy(name, *args, ft_strchr(*args, '=') - *args);
		ft_strlcpy(content, ft_strchr(*args, '=') + 1, ft_strlen(ft_strchr(*args, '=')));
		if (env_get_value(name, env))
			env_edit(name, content, env);
		else
			env_append(name, content, env);
		args++;
	}
}
