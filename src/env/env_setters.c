/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:42:52 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/09 14:34:39 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_create_first_el(char *env_line, t_env *env)
{
	char	*name;
	char	*content;

	content = ft_strdup(ft_strchr(env_line, '=') + 1);
	if (!content)
		return (-1);
	ft_strchr(env_line, '=')[0] = 0;
	name = ft_strdup(env_line);
	if (!name)
	{
		free(content);
		return (-1);
	}
	env->name = name;
	env->content = content;
	env->next = NULL;
	return (0);
}

t_env	*env_create_el(char *env_line)
{
	t_env	*new;
	char	*name;
	char	*content;

	content = ft_strdup(ft_strchr(env_line, '=') + 1);
	if (!content)
		return (NULL);
	ft_strchr(env_line, '=')[0] = 0;
	name = ft_strdup(env_line);
	if (!name)
	{
		free(content);
		return (NULL);
	}
	new = ft_envnew(name, content);
	return (new);
}

t_env	*env_init(char **env_d)
{
	t_env	*env;
	t_env	*new;
	int		i;

	i = -1;
	env = NULL;
	while (env_d[++i])
	{
		new = env_create_el(env_d[i]);
		if (!new)
		{
			ft_envclear(&env, free);
			return (NULL);
		}
		ft_envadd_back(&env, new);
	}
	return (env);
}

char	**env_get(t_env *env)
{
	char	**exec_env;
	int		i;

	exec_env = malloc(sizeof(char *) * (ft_envsize(env) + 1));
	if (!exec_env)
		return (exec_env);
	exec_env[ft_envsize(env)] = NULL;
	i = 0;
	while (env)
	{
		exec_env[i] = malloc(ft_strlen(env->name)
				+ ft_strlen(env->content) + 2);
		if (!exec_env[i])
		{
			ft_free("a", exec_env);
			return (NULL);
		}
		ft_strlcpy(exec_env[i], env->name, ft_strlen(env->name) + 1);
		exec_env[i][ft_strlen(env->name)] = '=';
		ft_strlcpy(exec_env[i] + ft_strlen(env->name) + 1,
			env->content, ft_strlen(env->content) + 1);
		env = env->next;
		i++;
	}
	return (exec_env);
}
