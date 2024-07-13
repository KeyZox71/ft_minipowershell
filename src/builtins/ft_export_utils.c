/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:59:27 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/13 16:10:28 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_make_str(char *str, char *name, char *content)
{
	if (!content)
		ft_strlcpy(str, name, ft_strlen(name) + 1);
	else
	{
		ft_strlcpy(str, name, ft_strlen(name) + 1);
		str[ft_strlen(name)] = '=';
		ft_strlcat(str, content, ft_vstrlen(2, str, content) + 1);
	}
}

char	**env_get_list(t_env *env)
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
		if (ft_strcmp(env->name, "_"))
		{
			ar[i] = ft_calloc(1, ft_vstrlen(2, env->name, env->content) + 2);
			if (!ar[i])
			{
				ft_free("a", ar);
				return (NULL);
			}
			env_make_str(ar[i], env->name, env->content);
			i++;
		}
		env = env->next;
	}
	return (ar);
}

void	add_to_env(char *name, char *content, t_env *env)
{
	if (!content)
		content = ft_calloc(1, 1);
	if (!content)
		return ;
	if (env_get_value(name, env))
		env_edit(name, content, env);
	else
		ft_envadd_back(&env, ft_envnew(name, content));
}
