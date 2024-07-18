/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_to_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:24:15 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/18 14:15:18 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

t_env	**get_env(t_env **env)
{
	static t_env	**ret;

	if (env)
		ret = env;
	return (ret);
}

t_list	**get_list(t_list **list)
{
	static t_list	**ret;

	if (list)
		ret = list;
	return (ret);
}

t_list	**get_list2(t_list **list)
{
	static t_list	**ret;

	if (list)
		ret = list;
	return (ret);
}

int	get_exit_code(int in)
{
	static int	exit_code;

	if (in == 727)
	{
		exit_code = 727;
		return (exit_code);
	}
	if (in != -1)
		exit_code = in % 256;
	if (exit_code < 0)
		exit_code += 256;
	return (exit_code);
}

int	get_fd_heredoc(int in)
{
	static int	fd;

	if (in != -1)
		fd = in;
	return (fd);
}
