/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:42:36 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/11 15:25:29 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint	ft_strlen(const char *s)
{
	uint	result;

	result = 0;
	if (!s)
		return (0);
	while (s[result])
		result++;
	return (result);
}

uint	ft_vstrlen(int len, ...)
{
	va_list	argsl;
	int		total_len;

	va_start(argsl, len);
	total_len = 0;
	while (len)
	{
		total_len += ft_strlen(va_arg(argsl, const char *));
		len--;
	}
	return (total_len);
}
