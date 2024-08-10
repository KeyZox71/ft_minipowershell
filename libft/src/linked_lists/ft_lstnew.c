/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:02:40 by mmoussou          #+#    #+#             */
/*   Updated: 2024/08/10 13:57:35 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*r;

	if (!content || !*content)
		return (NULL);
	r = malloc(sizeof(t_list));
	if (!r)
		return (NULL);
	r->content = content;
	r->next = NULL;
	return (r);
}
