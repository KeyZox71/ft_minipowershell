/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:19:39 by mmoussou          #+#    #+#             */
/*   Updated: 2024/05/21 00:34:48 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_heredoc(char *delimiter)
{
	int		fork_pid;
	int		tmp_fd;
	int		status;
	char	*line;

	tmp_fd = open("/tmp/.minishell-heredoc", O_RDONLY | O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (tmp_fd == -1)
		return (-1);
	fork_pid = fork();
	if (fork_pid == -1)
	{
		close(tmp_fd);
		return (-1);
	}
	if (!fork_pid)
	{
		line = readline("heredoc> ");
		while (ft_strcmp(line, delimiter))
		{
			status = write(tmp_fd, line, ft_strlen(line));
			status = write(tmp_fd, "\n", 1);
			free(line);
			line = readline("heredoc> ");
		}
		free(line);
		status = write(tmp_fd, "\0", 1);
		if (status == -1)
		{
			close(tmp_fd);
			return (-1);
		}
	}
	else
		waitpid(fork_pid, NULL, 0);
	return (tmp_fd);
}
