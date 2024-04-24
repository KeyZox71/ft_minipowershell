/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:50:36 by adjoly            #+#    #+#             */
/*   Updated: 2024/03/16 21:47:28 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printconversion(char conversion, va_list args);
int		ft_putnbrulong(unsigned int n);
int		ft_putaddr(void *ptr);

int		ft_putstr_p(char *s);

int		ft_putnbrbase_p(unsigned long int n, char *base);
int		ft_pputnbrbase(unsigned int n, char *base);
int		ft_putchar_p(char c);
int		ft_putnbr_p(int n);
size_t	ft_strlen(const char *s);

#endif
