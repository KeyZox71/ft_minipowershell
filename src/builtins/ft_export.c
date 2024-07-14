/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:42:36 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/14 13:52:32 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

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

	env = env_get_list(env_l);
	if (!env)
		return ;
	ft_arraysort(env);
	i = 0;
	while (env[i])
	{
		printf("declare -x %s\n", env[i]);
		i++;
	}
	ft_free("a", &env);
	return ;
}

int	export_value(char *arg, t_env *env)
{
	char	*name;
	char	*content;

	if (!strchr(arg, '='))
	{
		name = ft_strdup(arg);
		if (name)
			add_to_env(name, NULL, env);
		return (-1);
	}
	name = ft_calloc(sizeof(char), ft_strchr(arg, '=') - arg + 1);
	content = ft_calloc(sizeof(char), ft_strlen(ft_strchr(arg, '=')));
	if (!name || !content)
	{
		ft_free("cc", &name, &content);
		return (-1);
	}
	ft_strlcpy(name, arg, ft_strchr(arg, '=') - arg + 1);
	ft_strlcpy(content, ft_strchr(arg, '=') + 1,
		ft_strlen(ft_strchr(arg, '=')) + 1);
	add_to_env(name, content, env);
	return (0);
}

void	ft_export(char **args, t_env *env)
{
	int	status;

	if (!args || !args[0])
	{
		env_print_in_order(env);
		return ;
	}
	while (*args)
	{
		status = export_value(*args, env);
		if (status)
			return ;
		args++;
	}
}
