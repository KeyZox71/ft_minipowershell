/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:40:46 by mmoussou          #+#    #+#             */
/*   Updated: 2024/04/30 11:06:32 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_envdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->name);
	del(lst->content);
	free(lst);
	lst = NULL;
}
