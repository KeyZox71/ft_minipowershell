/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:55:45 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/13 19:46:01 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little || !little[0] || big == little)
		return ((char *)big);
	if (!len || !big)
		return (NULL);
	while (i < len && big[i])
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
			j++;
		if (j == (size_t)ft_strlen(little))
			return (&((char *)big)[i]);
		i++;
	}
	return (NULL);
}
