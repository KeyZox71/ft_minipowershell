/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacklast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:36:13 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/18 00:36:15 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
		return (stack);
	}
	return (NULL);
}
