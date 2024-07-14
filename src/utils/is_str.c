/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:23:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/03 10:23:55 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_str(char *src, char *dst)
{
	while (*src && *dst && *src == *dst)
	{
		src++;
		dst++;
	}
	if (*dst)
		return (false);
	return (true);
}
