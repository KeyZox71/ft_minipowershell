/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:39:58 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/10 16:42:29 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_envprint(t_env *env)
{
	while (env)
	{
		printf("%s:%s\n", env->name, env->content);
		env = env->next;
	}
}
