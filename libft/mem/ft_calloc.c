/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:02:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/03/04 10:10:58 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (((unsigned long long)(size * nmemb) > 4294967295))
		return (NULL);
	if ((int)size < 0 && (int)nmemb < 0)
		return (NULL);
	result = malloc(size * nmemb);
	if (!result)
		return (NULL);
	while (i < (size * nmemb))
	{
		*(unsigned char *)(result + i) = '\0';
		i++;
	}
	return (result);
}
