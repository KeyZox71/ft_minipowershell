/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:19:39 by mmoussou          #+#    #+#             */
/*   Updated: 2024/05/23 07:18:01 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	# mode
		0: ouvre un nouveau fichier
		<fd>: close ce fd
		-1: pour signifier qu'il faut decrémenter la static
 */
int	fd_manager(int mode)
{
	static int	index = 0;
	char		*index_itoa;
	char		*path;
	int			fd;

	if (mode > 0)
		close(mode);
	if (mode)
	{
		index--;
		return (0);
	}
	path = ft_calloc(sizeof(char), 24 + 3);
	if (!path)
		return (-1);
	index_itoa = ft_itoa(index);
	if (!index_itoa)
		free(path);
	if (!index_itoa)
		return (-1);
	index++;
	strcat(path, "/tmp/.minishell-heredoc-");
	strcat(path, index_itoa);
	fd = open(path, O_RDONLY | O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (fd);
}

static int	get_input(char *delimiter, int fd)
{
	char	*line;
	int		status;

	printf("%s | ", delimiter);
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
	if (status == -1)
		return (-1);
	return (0);
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
		fd_manager(fd);
		return (-1);
	}
	if (!fork_pid)
	{
		get_input(delimiter, fd);
		exit(0);
	}
	else
		waitpid(fork_pid, NULL, 0);
	return (fd);
}
