/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:44:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/02/04 14:48:34 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(s);
	i = len_s;
	if (c == 0)
		return (&((char *)s)[len_s]);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	if (s[0] == (char)c)
		return (&((char *)s)[0]);
	return (NULL);
}
