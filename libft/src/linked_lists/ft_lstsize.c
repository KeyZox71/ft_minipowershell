/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:33:51 by mmoussou          #+#    #+#             */
/*   Updated: 2024/04/11 14:33:42 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint	ft_lstsize(t_list *lst)
{
	uint	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
