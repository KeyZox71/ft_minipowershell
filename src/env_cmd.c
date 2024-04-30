/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:53:11 by mmoussou          #+#    #+#             */
/*   Updated: 2024/04/30 12:54:48 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_envsize(t_env	*env)
{
	(void)env;
	return (0);
}

char	**get_env(t_env *env)
{
	char	**exec_env;
	int		i;

	exec_env = malloc(sizeof(char *) * ft_envsize(env));
	if (!exec_env)
		return (exec_env);
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
		ft_strlcpy(exec_env[i], env->name, ft_strlen(env->name));
		exec_env[i][ft_strlen(env->name)] = '=';
		ft_strlcpy(exec_env[i] + ft_strlen(env->name) + 1, \
			env->content, ft_strlen(env->content));
		env = env->next;
		i++;
	}
	return (exec_env);
}

char	set_env(char **env, const char *name, char *content)
{
	char	*new_env;
	int		i;
	int		j;

	if (!name || !name[0])
		return (0);
	for (int pog = 0; env[pog]; pog++)
		printf("%s\n", env[pog]);
	new_env = malloc(sizeof(char) * (ft_strlen(name) + ft_strlen(content) + 2));
	if (!new_env)
		return (-1);
	i = 0;
	while (name[i])
	{
		new_env[i] = name[i];
		i++;
	}
	new_env[i++] = '=';
	j = 0;
	while (content[j])
	{
		new_env[i + j] = content[j];
		j++;
	}
	printf("\n%s\n\n", new_env);
	return (0);
}
