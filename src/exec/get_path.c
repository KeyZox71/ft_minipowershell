/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:42:17 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/13 14:19:20 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_path_access(char *path, char *cmd)
{
	char	*abs_path;

	abs_path = ft_strjoin(path, "/");
	if (!abs_path)
		return (NULL);
	abs_path = ft_strjoin_free_s1(abs_path, cmd);
	if (!abs_path)
		return (NULL);
	if (access(abs_path, X_OK) == 0)
		return (abs_path);
	free(abs_path);
	return (NULL);
}

char	*get_path(char *path, char *cmd)
{
	char	**path_dir;
	int		i;

	if (!path)
		return (NULL);
	path_dir = ft_split(path, ':');
	if (!path_dir)
		return (NULL);
	i = 0;
	while (path_dir[i])
	{
		path = check_path_access(path_dir[i], cmd);
		if (path)
		{
			ft_free("ac", &path_dir, &cmd);
			return (path);
		}
		i++;
	}
	ft_free("ac", &path_dir, &cmd);
	return (path);
}
