/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:57:44 by adjoly            #+#    #+#             */
/*   Updated: 2024/02/04 14:41:30 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbrbase_fd(int n, char *base, int fd)
{
	unsigned int	nbr;
	size_t			base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr < base_len)
		write(fd, &base[nbr % base_len], 1);
	else
	{
		ft_putnbrbase_fd(nbr / base_len, base, fd);
		write(fd, &base[nbr % base_len], 1);
	}
}
