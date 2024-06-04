/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:19:39 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/05 01:21:06 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	# mode
		0: ouvre un nouveau fichier
		1: réouvre le fichier pour la lecture
		-1: pour signifier qu'il faut decrémenter la static
 */
int	fd_manager(int mode)
{
	static int	index = 0;
	char		*index_itoa;
	char		*path;
	int			fd;

	if (mode < 0)
		index--;
	if (mode < 0)
		return (0);
	path = ft_calloc(sizeof(char), 24 + 3);
	if (!path)
		return (-1);
	index_itoa = ft_itoa(index);
	if (!index_itoa)
		free(path);
	if (!index_itoa)
		return (-1);
	index++;
	ft_strlcat(path, "/tmp/.minishell-heredoc-", 24);
	ft_strlcat(path, index_itoa, ft_strlen(index_itoa));
	if (mode > 0)
		fd = open(path, O_RDONLY);
	else
		fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (fd);
}

static int	get_input(char *delimiter, int fd)
{
	char	*line;
	int		status;

	line = readline("heredoc> ");
	while (ft_strcmp(line, delimiter))
	{
		status = write(fd, line, ft_strlen(line));
		if (status == -1)
			fd_manager(fd);
		if (status == -1)
			return (-1);
		status = write(fd, "\n", 1);
		if (status == -1)
			fd_manager(fd);
		if (status == -1)
			return (-1);
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
	status = write(fd, "\0", 1);
	if (status == -1)
		fd_manager(fd);
	return (-(status == -1));
}

int	ft_heredoc(char *delimiter)
{
	int		fork_pid;
	int		fd;

	fd = fd_manager(0);
	if (fd == -1)
	{
		fd_manager(-1);
		return (-1);
	}
	fork_pid = fork();
	if (fork_pid == -1)
	{
		fd_manager(-1);
		close(fd);
		return (-1);
	}
	if (!fork_pid)
	{
		get_input(delimiter, fd);
		exit(0);
	}
	else
		waitpid(fork_pid, NULL, 0);
	return (fd_manager(1));
}
