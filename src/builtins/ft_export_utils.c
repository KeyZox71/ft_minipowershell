/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:59:27 by mmoussou          #+#    #+#             */
/*   Updated: 2024/08/14 07:50:39 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	ft_arraylen(char **s)
{
	char	**endptr;

	endptr = s;
	while (*endptr)
		endptr++;
	return (endptr - s);
}

void	env_make_str(char *str, char *name, char *content)
{
	if (!content)
		ft_strlcpy(str, name, ft_strlen(name) + 1);
	else
	{
		ft_strlcpy(str, name, ft_strlen(name) + 1);
		str[ft_strlen(name)] = '=';
		ft_strlcat(str, "\"", ft_strlen(str) + 2);
		ft_strlcat(str, content, ft_vstrlen(2, str, content) + 1);
		ft_strlcat(str, "\"", ft_strlen(str) + 2);
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
			ar[i] = ft_calloc(1, ft_vstrlen(2, env->name, env->content) + 4);
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
	t_env	*env_t;

	env_t = env;
	while (env_t && ft_strcmp(env_t->name, name))
		env_t = env_t->next;
	if (env_t)
	{
		if (content)
			env_edit(name, content, env);
		free(name);
	}
	else
		ft_envadd_back(&env, ft_envnew(name, content));
}

int	check_export_input(char *s)
{
	int	i;

	i = 0;
	if ((!ft_isalpha(s[i]) && s[i] != '_') || s[i] == '=')
	{
		ft_printf_fd(2, "minishell: export: '%s': not a valid identifier\n", s);
		return (get_exit_code(1));
	}
	i++;
	while (s[i] && s[i] != '=')
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
		{
			if (s[i] == '+' && s[i + 1] == '=')
			{
				i++;
				continue ;
			}
			ft_printf_fd(2,
				"minishell: export: '%s': not a valid identifier\n", s);
			return (get_exit_code(1));
		}
		i++;
	}
	return (get_exit_code(0));
}
