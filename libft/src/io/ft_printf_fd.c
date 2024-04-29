/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:46:39 by mmoussou          #+#    #+#             */
/*   Updated: 2024/02/05 14:17:15 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putptr_fd(unsigned long long value, int fd)
{
	if (!value)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (ft_putuhex_fd(value, "0123456789abcdef", fd) + 2);
}

static int	ft_putstack_fd(t_stack *s, int fd)
{
	if (s)
	{
		return (ft_printf_fd(fd, "nb_init:%d | nb:%d\n", s->nb_init, s->nb)
			+ ft_putstack_fd(s->next, fd));
	}
	return (0);
}

static void	print_arg_fd(va_list argsl, char type, size_t *l, int fd)
{
	if (type == 'c')
		*l += ft_putchar_fd(va_arg(argsl, int), fd);
	else if (type == 's')
		*l += ft_putstr_fd(va_arg(argsl, char *), fd);
	else if (type == 'p')
		*l += ft_putptr_fd(va_arg(argsl, unsigned long long), fd);
	else if (type == 'd' || type == 'i')
		*l += ft_putnbr_fd(va_arg(argsl, int), fd);
	else if (type == 'u')
		*l += ft_putnbr_fd(va_arg(argsl, uint32_t), fd);
	else if (type == 'x')
		*l += ft_putuhex_fd(va_arg(argsl, uint32_t), "0123456789abcdef", fd);
	else if (type == 'X')
		*l += ft_putuhex_fd(va_arg(argsl, uint32_t), "0123456789ABCDEF", fd);
	else if (type == 'S')
		*l += ft_putstack_fd(va_arg(argsl, t_stack *), fd);
	else if (type)
	{
		*l += ft_putchar_fd('%', 1);
		if (type != '%')
			*l += ft_putchar_fd(type, 1);
	}
	else
		*l = -1;
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	argsl;
	size_t	i;
	size_t	l;

	if (!str)
		return (-1);
	va_start(argsl, str);
	i = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] == '%')
			print_arg_fd(argsl, str[++i], &l, fd);
		else
			l += ft_putchar_fd(str[i], fd);
		if (str[i])
			i++;
	}
	va_end(argsl);
	return (l);
}
