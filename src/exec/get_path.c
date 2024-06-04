/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:42:17 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/02 21:05:25 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_path_list(char *path, t_list *list_entry)
{
	DIR				*path_dir;
	struct dirent	*dir_entry;
	char			*abs_path;
	struct stat		entry;
	t_list			*new_list_entry;

	path_dir = opendir(path);
	if (!path_dir)
		return (-1);
	dir_entry = readdir(path_dir);
	while (dir_entry)
	{
		if (!ft_strncmp(dir_entry->d_name, ".", ft_strlen(dir_entry->d_name))
			|| !ft_strncmp(dir_entry->d_name, "..",
				ft_strlen(dir_entry->d_name)))
		{
			dir_entry = readdir(path_dir);
			continue ;
		}
		abs_path = ft_calloc(sizeof(char), strlen(path)
				+ strlen(dir_entry->d_name) + 2);
		if (!abs_path)
			return (-1);
		strcat(abs_path, path);
		strcat(abs_path, "/");
		strcat(abs_path, dir_entry->d_name);
		stat(abs_path, &entry);
		if (S_ISREG(entry.st_mode)
			&& (entry.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
		{
			if (list_entry->content == NULL)
				list_entry->content = abs_path;
			else
			{
				new_list_entry = ft_lstnew(abs_path);
				if (!new_list_entry)
					return (-1);
				ft_lstadd_back(&list_entry, new_list_entry);
			}
		}
		dir_entry = readdir(path_dir);
	}
	closedir(path_dir);
	return (0);
}

char	**get_path(char *path)
{
	char	**path_dir;
	char	**path_list;
	t_list	*list_entry;
	int		i;

	list_entry = ft_lstnew(NULL);
	path_dir = ft_split(path, ':');
	if (!path_dir)
		return (NULL);
	i = 0;
	while (path_dir[i])
	{
		get_path_list(path_dir[i], list_entry);
		i++;
	}
	i = 0;
	path_list = ft_calloc(sizeof(char *), ft_lstsize(list_entry) + 1);
	while (list_entry)
	{
		path_list[i] = list_entry->content;
		list_entry = list_entry->next;
		i++;
	}
	ft_free("al", &path_dir, &list_entry);
	return (path_list);
}
