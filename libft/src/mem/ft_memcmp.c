/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:57:12 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/13 19:47:03 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	if (!n)
		return (0);
	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	while (i < (n - 1) && *ptr1 == *ptr2)
	{
		ptr1++;
		ptr2++;
		i++;
	}
	return (*ptr1 - *ptr2);
}
