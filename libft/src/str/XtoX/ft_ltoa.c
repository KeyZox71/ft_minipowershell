/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:45:53 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/12 00:52:12 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_size(int n)
{
	int	s;

	s = 0;
	if (n <= 0)
	{
		s++;
		n *= -1;
	}
	while (n >= 1)
	{
		s++;
		n /= 10;
	}
	return (s);
}

static size_t	pwten(int n)
{
	int	i;

	i = 1;
	while (n)
	{
		i *= 10;
		n--;
	}
	return (i);
}

static char	*itoa_rec(char *r, int n)
{
	int	i;

	if (n > 9)
	{
		r[0] = n / (pwten(n_size(n) - 1)) + '0';
		i = 1;
		while (n_size(n) - (n_size(n % pwten(n_size(n) - 1))) != i)
		{
			r[i] = '0';
			i++;
		}
		itoa_rec(&r[n_size(n) - (n_size(n % pwten(n_size(n) - 1)))], \
				n % pwten(n_size(n) - 1));
		return (r);
	}
	r[0] = n + '0';
	return (r);
}

char	*ft_ltoa(long long n)
{
	char	*r;

	if (n == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	r = ft_calloc(sizeof(char), n_size(n) + 1);
	if (!r)
		return (NULL);
	if (n == 0)
	{
		r[0] = '0';
		return (r);
	}
	if (n < 0)
	{
		r[0] = '-';
		itoa_rec(&r[1], n * -1);
		return (r);
	}
	itoa_rec(r, n);
	return (r);
}
