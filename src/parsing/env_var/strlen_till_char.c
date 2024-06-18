/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_till_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 01:09:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/09 14:02:35 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	strlen_till_char(char *s, int c)
{
	char	*tmp;
	size_t	size;

	tmp = s;
	size = 0;
	while (*tmp && *tmp != c)
	{
		tmp++;
		size++;
	}
	return (size);
}
