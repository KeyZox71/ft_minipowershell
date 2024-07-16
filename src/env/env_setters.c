/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:42:52 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/16 13:19:36 by mmoussou         ###   ########.fr       */
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

void	fill_env_get(char *name, char *content, char *str)
{
	ft_strlcpy(str, name, ft_strlen(name) + 1);
	str[ft_strlen(name)] = '=';
	if (content)
		ft_strlcat(str, content, ft_vstrlen(2, str, content) + 1);
}

char	**env_get(t_env *env)
{
	char	**ar;
	int		i;

	ar = ft_calloc(sizeof(char *), (ft_envsize(env) + 1));
	if (!ar)
		return (ar);
	ar[ft_envsize(env)] = NULL;
	i = 0;
	while (env)
	{
		if (env->content)
		{
			ar[i] = ft_calloc(1, ft_vstrlen(2, env->name, env->content) + 2);
			if (!ar[i])
			{
				ft_free("a", ar);
				return (NULL);
			}
			fill_env_get(env->name, env->content, ar[i]);
			i++;
		}
		env = env->next;
	}
	return (ar);
}
