/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:03:15 by mmoussou          #+#    #+#             */
/*   Updated: 2024/04/30 11:06:17 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_envadd_front(t_env **lst, t_env *new)
{
	t_env	*tmp;

	tmp = *lst;
	*lst = new;
	if (!new || !lst)
		return ;
	while (new->next)
		new = new->next;
	new->next = tmp;
}
