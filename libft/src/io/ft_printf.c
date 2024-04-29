/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:46:39 by mmoussou          #+#    #+#             */
/*   Updated: 2024/02/05 14:14:59 by mmoussou         ###   ########.fr       */
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

static int	ft_putstack_fd(t_stack *stack, int fd)
{
	if (stack)
	{
		return (ft_printf("nb_init:%d | nb:%d\n", stack->nb_init, stack->nb)
			+ ft_putstack_fd(stack->next, fd));
	}
	return (0);
}

static void	print_arg(va_list argsl, char type, size_t *l)
{
	if (type == 'c')
		*l += ft_putchar_fd(va_arg(argsl, int), 1);
	else if (type == 's')
		*l += ft_putstr_fd(va_arg(argsl, char *), 1);
	else if (type == 'p')
		*l += ft_putptr_fd(va_arg(argsl, unsigned long long), 1);
	else if (type == 'd' || type == 'i')
		*l += ft_putnbr_fd(va_arg(argsl, int), 1);
	else if (type == 'u')
		*l += ft_putnbr_fd(va_arg(argsl, unsigned int), 1);
	else if (type == 'x')
		*l += ft_putuhex_fd(va_arg(argsl, unsigned int), "0123456789abcdef", 1);
	else if (type == 'X')
		*l += ft_putuhex_fd(va_arg(argsl, unsigned int), "0123456789ABCDEF", 1);
	else if (type == 'S')
		*l += ft_putstack_fd(va_arg(argsl, t_stack *), 1);
	else if (type)
	{
		*l += ft_putchar_fd('%', 1);
		if (type != '%')
			*l += ft_putchar_fd(type, 1);
	}
	else
		*l = -1;
}

int	ft_printf(const char *str, ...)
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
			print_arg(argsl, str[++i], &l);
		else
			l += ft_putchar_fd(str[i], 1);
		if (str[i])
			i++;
	}
	va_end(argsl);
	return (l);
}
