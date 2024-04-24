/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:57:44 by adjoly            #+#    #+#             */
/*   Updated: 2024/02/04 15:21:56 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrbase_pf(unsigned int n, char *base)
{
	unsigned int	base_len;
	int				len;

	len = 0;
	base_len = (int)ft_strlen(base);
	if (n < base_len)
		len += write(1, &base[n % base_len], 1);
	else
	{
		len += ft_putnbrbase_pf(n / base_len, base);
		len += write(1, &base[n % base_len], 1);
	}
	return (len);
}

int	ft_putnbrbase_p(unsigned long int n, char *base)
{
	unsigned long int	base_len;
	int					len;

	len = 0;
	base_len = (int)ft_strlen(base);
	if (n < base_len)
		len += write(1, &base[n % base_len], 1);
	else
	{
		len += ft_putnbrbase_p(n / base_len, base);
		len += write(1, &base[n % base_len], 1);
	}
	return (len);
}
