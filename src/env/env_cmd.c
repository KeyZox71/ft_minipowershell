/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:09:50 by mmoussou          #+#    #+#             */
/*   Updated: 2024/05/09 15:54:22 by adjoly           ###   ########.fr       */
/*   Updated: 2024/05/07 13:58:48 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		return (-1);
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
		return (NULL);
	new = ft_envnew(name, content);
	return (new);
}

int	env_init(char **env_d, t_env *env)
{
	t_env	*new;
	int		i;
	char	bool_first_el;

	i = 0;
	bool_first_el = true;
	while (env_d[i])
	{
		if (bool_first_el)
			i = env_create_first_el(env_d[i], env);
		if (bool_first_el && i < 0)
			return (1);
		if (bool_first_el)
			bool_first_el = false;
		else
		{
			new = env_create_el(env_d[i]);
			if (!new)
			{
				ft_envclear(&env, free);
				return (1);
			}
			ft_envadd_back(&env, new);
		}
		i++;
	}
	return (0);
}

int	env_append(char *name, char *content, t_env *env)
{
	char	*new_content;

	while (env && ft_strcmp(env->name, name))
		env = env->next;
	if (!env)
		return (-1);
	new_content = ft_calloc(1, ft_strlen(env->content) + ft_strlen(content));
	ft_strlcpy(new_content, env->content, ft_strlen(env->content) + 1);
	ft_strlcpy(new_content + ft_strlen(env->content),
		content, ft_strlen(content) + 1);
	free(env->content);
	env->content = new_content;
	return (0);
}

int	env_edit(char *name, char *content, t_env *env)
{
	while (env && ft_strcmp(env->name, name))
		env = env->next;
	if (!env)
		return (-1);
	free(env->content);
	env->content = content;
	return (0);
}

int	env_delete(char *name, t_env *env)
{
	t_env	*tmp;

	while (env && env->next && ft_strcmp(env->next->name, name))
		env = env->next;
	if (!env || !env->next)
		return (-1);
	ft_free("cc", &env->next->name, &env->next->content);
	tmp = env->next;
	env->next = env->next->next;
	free(tmp);
	return (0);
}

void	env_print(t_env *env)
{
	while (env)
	{
		printf("%s:%s\n", env->name, env->content);
		env = env->next;
	}
}
