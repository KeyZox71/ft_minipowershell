/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hostname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:36:31 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/21 20:55:19 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "libft.h"

char	*get_fullhostname(char *buf)
{
	char	*hostname;
	char	*delimiter;

	hostname = ft_strdup(buf);
	free(buf);
	delimiter = ft_strchr(hostname, '\n');
	if (delimiter)
		hostname[delimiter - hostname] = '\0';
	return (hostname);
}

char	*__get_host_str(void)
{
	int		host_file;
	char	*buf;

	buf = ft_calloc(254, sizeof(char));
	if (!buf)
		return (ft_strdup("nixos"));
	host_file = open("/etc/hostname", O_RDONLY);
	if (host_file <= -1)
	{
		free(buf);
		return (ft_strdup("nixos"));
	}
	read(host_file, buf, 254);
	close(host_file);
	return (buf);
}

char	*get_hostname(void)
{
	char	*hostname;
	char	*buf;
	char	*delimiter;

	buf = __get_host_str();
	delimiter = ft_strchr(buf, '.');
	if (!delimiter)
		return (get_fullhostname(buf));
	hostname = ft_calloc(delimiter - buf + 1, sizeof(char));
	if (!hostname)
	{
		free(buf);
		return (ft_strdup("nixos"));
	}
	ft_strlcpy(hostname, buf, delimiter - buf + 1);
	free(buf);
	return (hostname);
}
