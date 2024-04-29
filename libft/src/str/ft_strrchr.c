/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:57:57 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/13 19:46:30 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!c)
		return (&((char *)s)[i]);
	while (i + 1)
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}
