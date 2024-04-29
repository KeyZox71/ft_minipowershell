/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:03:03 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/01 22:03:04 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (s)
	{
		ptr = (char *)s;
		while (i < n)
		{
			ptr[i] = c;
			i++;
		}
	}
	return (s);
}
