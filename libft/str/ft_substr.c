/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:59:58 by adjoly            #+#    #+#             */
/*   Updated: 2024/02/04 14:48:54 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (s == NULL)
		return (0);
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	if (len == 0 || start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
