/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:42:57 by mmoussou          #+#    #+#             */
/*   Updated: 2024/08/13 15:07:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_envadd_back(t_env **env, t_env *new)
{
	t_env	*tmp;

	if (!env)
		return ;
	if (!*env)
	{
		*env = new;
		return ;
	}
	tmp = ft_envlast(*env);
	tmp->next = new;
}
