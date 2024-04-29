/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:35:55 by mmoussou          #+#    #+#             */
/*   Updated: 2024/04/11 14:35:24 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint	ft_stacksize(t_stack *stack)
{
	uint	i;

	i = 0;
	if (stack)
	{
		i++;
		while (stack->next)
		{
			stack = stack->next;
			i++;
		}
	}
	return (i);
}
