/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:42:36 by mmoussou          #+#    #+#             */
/*   Updated: 2024/08/14 07:51:17 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

void	env_print_in_order(t_env *env_l, int fd)
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
		ft_printf_fd(fd, "declare -x %s\n", env[i]);
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
		return (0);
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

void	append_process(char *name, char *content, t_env *env_t, t_env *env)
{
	if (env_t)
	{
		if (env_t->content)
			env_append(name, content, env);
		else
			env_edit(name, content, env);
		free(name);
	}
	else
		ft_envadd_back(&env, ft_envnew(name, content));
}

int	export_append_value(char *arg, t_env *env)
{
	char	*name;
	char	*content;
	t_env	*env_t;

	name = ft_calloc(sizeof(char), ft_strchr(arg, '=') - arg);
	content = ft_calloc(sizeof(char), ft_strlen(ft_strchr(arg, '=')));
	if (!name || !content)
	{
		ft_free("cc", &name, &content);
		return (-1);
	}
	ft_strlcpy(name, arg, ft_strchr(arg, '=') - arg);
	ft_strlcpy(content, ft_strchr(arg, '=') + 1,
		ft_strlen(ft_strchr(arg, '=')) + 1);
	env_t = env;
	while (env_t && ft_strcmp(env_t->name, name))
		env_t = env_t->next;
	append_process(name, content, env_t, env);
	return (0);
}

void	ft_export(char **args, t_env *env, int fd)
{
	int	status;

	if (!args || !args[0])
	{
		env_print_in_order(env, fd);
		return ;
	}
	while (*args)
	{
		if (!check_export_input(*args))
		{
			if (ft_strchr(*args, '=') && (ft_strchr(*args, '=') - 1)[0] == '+')
				status = export_append_value(*args, env);
			else
				status = export_value(*args, env);
			if (status)
				return ;
		}
		args++;
	}
}
