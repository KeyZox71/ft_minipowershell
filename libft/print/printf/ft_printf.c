/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:48:37 by adjoly            #+#    #+#             */
/*   Updated: 2024/03/16 21:46:36 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(void *ptr)
{
	int	r;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	r = ft_putnbrbase_p((long unsigned int)ptr, "0123456789abcdef");
	return (2 + r);
}

int	ft_putnbrulong(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
		len += write(1, &(char){n + '0'}, 1);
	else
	{
		len += ft_putnbrulong(n / 10);
		len += write(1, &(char){n % 10 + '0'}, 1);
	}
	return (len);
}

int	ft_printconversion(char conversion, va_list args)
{
	int	count;

	count = 0;
	if (conversion == '%')
		count = ft_putchar_p('%');
	else if (conversion == 's')
		count = ft_putstr_p(va_arg(args, char *));
	else if (conversion == 'c')
		count = ft_putchar_p(va_arg(args, int));
	else if (conversion == 'i' || conversion == 'd')
		count = ft_putnbr_p(va_arg(args, int));
	else if (conversion == 'u')
		count = ft_putnbrulong(va_arg(args, unsigned int));
	else if (conversion == 'p')
		count = ft_putaddr(va_arg(args, void *));
	else if (conversion == 'x')
		count = ft_pputnbrbase(va_arg(args, unsigned long), "0123456789abcdef");
	else if (conversion == 'X')
		count = ft_pputnbrbase(va_arg(args, unsigned long), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				count += ft_printconversion(format[i], args);
			else
				return (-1);
		}
		else
			count += ft_putchar_p(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
