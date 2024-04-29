/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:48:12 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/03 22:02:08 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putuhex_fd(unsigned long long nbr, char *base, int fd)
{
	if (nbr < 16)
		return (ft_putchar_fd(base[nbr], 1));
	else
	{
		return (ft_putuhex_fd(nbr / 16, base, fd)
			+ ft_putchar_fd(base[nbr % 16], 1));
	}
}
