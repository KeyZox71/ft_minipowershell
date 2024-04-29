/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:02:34 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/01 22:08:52 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	i = 0;
	if (dst && src)
	{
		ptr1 = (char *)dst;
		ptr2 = (char *)src;
		while (i < n)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	return (dst);
}
