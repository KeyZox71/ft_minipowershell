/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:58:13 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/11 11:43:35 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	i = 0;
	if (dst && src)
	{
		ptr1 = (char *)dst;
		ptr2 = (char *)src;
		if (ptr1 > ptr2)
			while (n--)
				ptr1[n] = ptr2[n];
		else
		{
			while (i < n)
			{
				ptr1[i] = ptr2[i];
				i++;
			}
		}
	}
	return (dst);
}
