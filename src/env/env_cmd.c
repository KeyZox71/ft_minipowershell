/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:50:01 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/15 18:46:12 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_append(char *name, char *content, t_env *env)
{
	char	*new_content;
	t_env	*tmp_env;

	tmp_env = env;
	while (tmp_env && ft_strcmp(tmp_env->name, name))
		tmp_env = tmp_env->next;
	if (!tmp_env)
	{
		new_content = ft_strdup(name);
		if (!new_content)
			return (-1);
		ft_envadd_back(&env, ft_envnew(new_content, content));
		return (-1);
	}
	new_content = ft_calloc(1, ft_strlen(tmp_env->content)
			+ ft_strlen(content));
	if (!new_content)
		return (-1);
	ft_strlcpy(new_content, tmp_env->content, ft_strlen(tmp_env->content) + 1);
	ft_strlcpy(new_content + ft_strlen(tmp_env->content),
		content, ft_strlen(content) + 1);
	free(tmp_env->content);
	tmp_env->content = new_content;
	return (0);
}

int	env_edit(char *name, char *content, t_env *env)
{
	t_env	*tmp_env;
	char	*name_dup;

	tmp_env = env;
	while (tmp_env && ft_strcmp(tmp_env->name, name))
		tmp_env = tmp_env->next;
	if (!tmp_env)
	{
		name_dup = ft_strdup(name);
		if (!name_dup)
			return (-1);
		ft_envadd_back(&env, ft_envnew(name_dup, content));
		return (-1);
	}
	free(tmp_env->content);
	tmp_env->content = content;
	return (0);
}

int	env_delete(char *name, t_env *env)
{
	t_env	*tmp;

	if (!ft_strcmp(env->name, name))
	{
		ft_free("cc", &env->name, &env->content);
		env->name = env->next->name;
		env->content = env->next->content;
		env->next = env->next->next;
		return (0);
	}
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

char	*env_get_value(char *name, t_env *env)
{
	char	*value;

	while (env && ft_strcmp(env->name, name))
		env = env->next;
	if (env)
	{
		value = ft_strdup(env->content);
		return (value);
	}
	return (NULL);
}

char	*env_getn_value(char *name, t_env *env, int n)
{
	char	*value;

	while (env && ft_strncmp(env->name, name, n))
		env = env->next;
	if (env)
	{
		value = ft_strdup(env->content);
		return (value);
	}
	return (NULL);
}
