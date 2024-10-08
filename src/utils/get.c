/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:08:56 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/10 17:53:22 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_rl(char **rl)
{
	static char	**ret;

	if (rl)
		ret = rl;
	return (ret);
}

int	get_fd_heredoc(int in)
{
	static int	fd;

	if (in != -1)
		fd = in;
	return (fd);
}
