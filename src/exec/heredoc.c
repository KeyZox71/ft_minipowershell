/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:19:39 by mmoussou          #+#    #+#             */
/*   Updated: 2024/08/13 13:49:14 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	**get_list2(t_list **list);

/*
 * # mode
 *	0: ouvre un nouveau fichier
 *	1: réouvre le fichier pour la lecture
 *	-1: pour signifier qu'il faut decrémenter la static
 */
int	fd_manager(int mode)
{
	static int	index = 0;
	char		*index_itoa;
	char		*path;

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
	free(index_itoa);
	return (__open_fd_here(path, mode));
}

static int	get_input(char *delimiter, int fd)
{
	char	*line;
	int		status;

	line = readline("heredoc> ");
	while (line && ft_strcmp(line, delimiter))
	{
		status = write(fd, line, ft_strlen(line));
		if (status == -1)
			close(fd_manager(fd));
		if (status == -1)
			break ;
		status = write(fd, "\n", 1);
		if (status == -1)
			close(fd_manager(fd));
		if (status == -1)
			break ;
		free(line);
		line = readline("heredoc> ");
	}
	free(line);
	status = write(fd, "\0", 1);
	if (status == -1)
		close(fd_manager(fd));
	return (-(status == -1));
}

void	__forked(char *delimiter, int fd, t_list *list)
{
	ft_lstclear(&list, free_redir);
	signal(SIGINT, &__heredoc_sig);
	get_input(delimiter, fd);
	ft_free("a", (char ***)get_void(NULL));
	ft_envclear(get_env(NULL), free);
	ft_lstclear(get_list(NULL), free);
	ft_lstclear(get_list2(NULL), free_cmd);
	rl_clear_history();
	close(fd);
}

int	__heredoc(char *delimiter, t_list *list)
{
	int		fork_pid;
	int		fd;
	int		heredoc_ret;

	fd = fd_manager(0);
	if (fd == -1)
	{
		close(fd_manager(-1));
		return (-1);
	}
	fork_pid = fork();
	if (fork_pid == -1)
	{
		close(fd_manager(-1));
		close(fd);
		return (-1);
	}
	if (!fork_pid)
	{
		__forked(delimiter, fd, list);
		exit(0);
	}
	else
		waitpid(fork_pid, &heredoc_ret, 0);
	return (check_error(heredoc_ret, fd));
}

int	ft_heredoc(char *delimiter, t_list *list)
{
	int	fd;

	fd = __heredoc(delimiter, list);
	return (fd);
}
