/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:45:04 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/19 11:36:00 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pop_first_el(t_env *env)
{
	t_env	*tmp;

	ft_free("cc", &env->name, &env->content);
	env->name = env->next->name;
	env->content = env->next->content;
	tmp = env->next;
	env->next = env->next->next;
	free(tmp);
}

void	ft_unset_arg(char *arg, t_env *env)
{
	t_env	*tmp;

	if (!ft_strcmp(env->name, arg))
	{
		pop_first_el(env);
		return ;
	}
	while (env->next)
	{
		if (!ft_strcmp(env->next->name, arg))
		{
			ft_free("cc", &env->next->name, &env->next->content);
			tmp = env->next;
			env->next = env->next->next;
			free(tmp);
			return ;
		}
		env = env->next;
	}
}

void	ft_unset(char **args, t_env *env)
{
	while (*args)
	{
		ft_unset_arg(*args, env);
		args++;
	}
	get_exit_code(0);
}
