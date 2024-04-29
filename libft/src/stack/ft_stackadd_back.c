/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:36:32 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/18 00:39:38 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	tmp = ft_stacklast(*stack);
	tmp->next = new;
}
