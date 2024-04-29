/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:02:48 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/11 13:27:31 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dl;

	if (!size)
		return (ft_strlen(src));
	dl = ft_strlen(dst);
	if (size <= dl)
		return (size + ft_strlen(src));
	return (dl + ft_strlcpy(dst + dl, src, size - dl));
}
