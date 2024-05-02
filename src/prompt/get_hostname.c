/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hostname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:36:31 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/02 13:42:24 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "libft.h"

char	*get_hostname(void)
{
	char	*hostname;
	char	*buf;
	int		host_file;
	char	*delimiter;

	buf = ft_calloc(254, sizeof(char));
	host_file = open("/etc/hostname", O_RDONLY);
	read(host_file, buf, 254);
	delimiter = ft_strchr(buf, '.');
	if (!delimiter)
	{
		free(buf);
		return (buf);
	}
	hostname = ft_calloc(delimiter - buf, sizeof(char));
	ft_strlcpy(hostname, buf, delimiter - buf + 1);
	free(buf);
	return (hostname);
}
