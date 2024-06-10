/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 01:42:17 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/10 17:49:21 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_element_to_list(t_list *list_entry, char *abs_path)
{
	t_list		*new_list_entry;

	if (list_entry->content == NULL)
		list_entry->content = abs_path;
	else
	{
		new_list_entry = ft_lstnew(abs_path);
		if (!new_list_entry)
			return (-1);
		ft_lstadd_back(&list_entry, new_list_entry);
	}
	return (0);
}

int	add_path_to_list(char *path, struct dirent *dir_entry, t_list *list_entry)
{
	char		*abs_path;
	struct stat	entry;
	int			status;

	abs_path = ft_calloc(sizeof(char), strlen(path)
			+ strlen(dir_entry->d_name) + 3);
	if (!abs_path)
		return (-1);
	ft_strlcpy(abs_path, path, ft_strlen(path) + 1);
	ft_strlcat(abs_path, "/", ft_strlen(abs_path) + 2);
	ft_strlcat(abs_path, dir_entry->d_name, ft_strlen(abs_path)
		+ ft_strlen(dir_entry->d_name) + 1);
	stat(abs_path, &entry);
	if (S_ISREG(entry.st_mode)
		&& (entry.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
	{
		status = add_element_to_list(list_entry, abs_path);
		if (status)
		{
			free(abs_path);
			return (-1);
		}
	}
	return (0);
}

int	get_path_list(char *path, t_list *list_entry)
{
	DIR				*path_dir;
	struct dirent	*dir_entry;
	int				status;

	path_dir = opendir(path);
	if (!path_dir)
		return (-1);
	dir_entry = readdir(path_dir);
	while (dir_entry)
	{
		if (!ft_strncmp(dir_entry->d_name, ".", 2)
			|| !ft_strncmp(dir_entry->d_name, "..", 3))
		{
			dir_entry = readdir(path_dir);
			continue ;
		}
		status = add_path_to_list(path, dir_entry, list_entry);
		if (status)
			closedir(path_dir);
		if (status)
			return (-1);
		dir_entry = readdir(path_dir);
	}
	closedir(path_dir);
	return (0);
}

char	**path_trans_list_to_char(t_list *list_entry)
{
	char	**path_list;
	int		i;

	i = 0;
	path_list = ft_calloc(sizeof(char *), ft_lstsize(list_entry) + 1);
	if (!path_list)
		return (path_list);
	while (list_entry)
	{
		path_list[i] = list_entry->content;
		list_entry = list_entry->next;
		i++;
	}
	return (path_list);
}

char	**get_path(char *path)
{
	char	**path_dir;
	char	**path_list;
	t_list	*list_entry;
	int		i;

	if (!path)
		return (NULL);
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
	path_list = path_trans_list_to_char(list_entry);
	ft_free("al", &path_dir, &list_entry);
	return (path_list);
}
