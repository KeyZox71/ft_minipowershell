/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:52:46 by adjoly            #+#    #+#             */
/*   Updated: 2024/02/04 15:20:26 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_p(int n)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr < 10)
		len += write(1, &(char){nbr + '0'}, 1);
	else
	{
		len += ft_putnbr_p(nbr / 10);
		len += write(1, &(char){nbr % 10 + '0'}, 1);
	}
	return (len);
}
