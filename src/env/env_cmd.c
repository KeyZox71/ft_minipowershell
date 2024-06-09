/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:50:01 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/09 16:02:05 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_append(char *name, char *content, t_env *env)
{
	char	*new_content;

	while (env && ft_strncmp(env->name, name,
			max(ft_strlen(env->name), ft_strlen(name))))
		env = env->next;
	if (!env)
		return (-1);
	new_content = ft_calloc(1, ft_strlen(env->content) + ft_strlen(content));
	if (!new_content)
		return (-1);
	ft_strlcpy(new_content, env->content, ft_strlen(env->content) + 1);
	ft_strlcpy(new_content + ft_strlen(env->content),
		content, ft_strlen(content) + 1);
	free(env->content);
	env->content = new_content;
	return (0);
}

int	env_edit(char *name, char *content, t_env *env)
{
	while (env && ft_strncmp(env->name, name,
			max(ft_strlen(env->name), ft_strlen(name))))
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

	if (!ft_strncmp(env->name, name,
			max(ft_strlen(env->name), ft_strlen(name))))
	{
		ft_free("cc", &env->name, &env->content);
		env->name = env->next->name;
		env->content = env->next->content;
		env->next = env->next->next;
		return (0);
	}
	while (env && env->next && ft_strncmp(env->next->name, name,
			max(ft_strlen(env->next->name), ft_strlen(name))))
		env = env->next;
	if (!env || !env->next)
		return (-1);
	ft_free("cc", &env->next->name, &env->next->content);
	tmp = env->next;
	env->next = env->next->next;
	free(tmp);
	return (0);
}

char	*env_getn_value(char *name, t_env *env, int n)
{
	while (env && ft_strncmp(env->name, name, n))
		env = env->next;
	if (env)
		return (env->content);
	return (NULL);
}

void	env_print(t_env *env)
{
	while (env)
	{
		printf("%s:%s\n", env->name, env->content);
		env = env->next;
	}
}
