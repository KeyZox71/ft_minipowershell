/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:36:50 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/18 00:37:05 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = new;
	if (!new || !stack)
		return ;
	while (new->next)
		new = new->next;
	new->next = tmp;
}
