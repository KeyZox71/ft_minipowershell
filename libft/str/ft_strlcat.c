/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:59:31 by adjoly            #+#    #+#             */
/*   Updated: 2024/02/04 14:47:03 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	if (dst == NULL && size == 0)
		return (0);
	i = 0;
	j = ft_strlen(dst);
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size <= j)
		return (len_src + size);
	while (j < size - 1 && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len_src + len_dst);
}
