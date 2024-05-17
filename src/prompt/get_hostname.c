/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hostname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:36:31 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/17 13:53:43 by adjoly           ###   ########.fr       */
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
	if (!buf)
		return (ft_strdup("nixos"));
	host_file = open("/etc/hostname", O_RDONLY);
	if (host_file <= -1)
		return (ft_strdup("nixos"));
	read(host_file, buf, 254);
	delimiter = ft_strchr(buf, '.');
	if (!delimiter)
	{
		hostname = ft_strdup(buf);
		free(buf);
		delimiter = ft_strchr(hostname, '\n');
		if (delimiter)
			hostname[delimiter - hostname] = '\0';
		return (hostname);
	}
	hostname = ft_calloc(delimiter - buf + 1, sizeof(char));
	if (!hostname)
		return (ft_strdup("nixos"));
	ft_strlcpy(hostname, buf, delimiter - buf + 1);
	free(buf);
	return (hostname);
}
