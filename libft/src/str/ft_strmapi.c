/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:53:45 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/07 15:36:32 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*r;
	int		i;

	if (!s || !f)
		return ((char *)s);
	r = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = (*f)(i, s[i]);
		i++;
	}
	return (r);
}
