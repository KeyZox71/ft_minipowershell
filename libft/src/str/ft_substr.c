/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:46:28 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/11 11:45:52 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	size_t	nl;
	char	*r;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
	{
		r = ft_calloc(1, 1);
		return (r);
	}
	nl = ft_strlen(s + start);
	if (nl > len)
		nl = len;
	r = malloc((nl + 1) * sizeof(char));
	if (!r)
		return (NULL);
	r[nl] = 0;
	while (nl--)
		r[nl] = s[start + nl];
	return (r);
}
