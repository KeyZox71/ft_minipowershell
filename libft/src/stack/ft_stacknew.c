/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:35:18 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/18 00:35:30 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new_element;

	new_element = malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->nb_init = content;
	new_element->nb = -1;
	new_element->next = NULL;
	return (new_element);
}
