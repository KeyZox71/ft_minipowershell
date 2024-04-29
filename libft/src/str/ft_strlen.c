/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:42:36 by mmoussou          #+#    #+#             */
/*   Updated: 2024/04/16 18:09:42 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

uint	ft_strlen(const char *s)
{
	const char	*endptr;

	endptr = s;
	while (*endptr)
		endptr++;
	return (endptr - s);
}
