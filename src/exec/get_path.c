/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:42:17 by mmoussou          #+#    #+#             */
/*   Updated: 2024/05/19 04:33:52 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_path_list(char *path)
{
	DIR				*path_dir;
	struct dirent	*dir_entry;
	char			*abs_path;
	struct stat		entry;

	path_dir = opendir(path);
	if (!path_dir)
		return (-1);
	dir_entry = readdir(path_dir);
	while (dir_entry)
	{
		if (!ft_strncmp(dir_entry->d_name, ".", ft_strlen(dir_entry->d_name))
			|| !ft_strncmp(dir_entry->d_name, "..", ft_strlen(dir_entry->d_name)))
		{
			dir_entry = readdir(path_dir);
			continue ;
		}
		abs_path = ft_calloc(sizeof(char), strlen(path) + strlen(dir_entry->d_name) + 1);
		if (!abs_path)
			return (-1);
		strcat(abs_path, path);
		strcat(abs_path, dir_entry->d_name);
		stat(abs_path, &entry);
		if (S_ISREG(entry.st_mode)
			&& (entry.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
			printf("%s\n", dir_entry->d_name);
		free(abs_path);
		dir_entry = readdir(path_dir);
	}
	closedir(path_dir);
	return (0);
}

int	get_path(char *path)
{
	char	**path_dir;
	int		i;

	path_dir = ft_split(path, ':');
	if (!path_dir)
		return (-1);
	i = 0;
	while (path_dir[i])
	{
		get_path_list(path_dir[i]);
		i++;
	}
	ft_free("a", &path_dir);
	return (0);
}
