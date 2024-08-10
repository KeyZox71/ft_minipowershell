/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 01:14:10 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/10 12:43:36 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include "minishell.h"

t_list	**get_list2(t_list **list);

int	__open_fd_here(char *path, int mode)
{
	int	fd;

	if (mode > 0)
		fd = open(path, O_RDONLY);
	else
		fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	free(path);
	get_fd_heredoc(fd);
	return (fd);
}

void	ft_lstclear_till_nxt(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	if (!(*lst)->next)
	{
		free(*lst);
		return ;
	}
	while (lst && *lst && (*lst)->next && del)
	{
		tmp = (*lst)->next;
		if ((*lst)->content)
			ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free(*lst);
}

int	check_error(int heredoc_ret, int fd)
{
	heredoc_ret = WEXITSTATUS(heredoc_ret);
	if (heredoc_ret != 0)
	{
		close(fd);
		get_exit_code(heredoc_ret);
		return (-2);
	}
	close(fd);
	return (fd_manager(1));
}

void	__heredoc_sig(int code)
{
	(void)code;
	ft_envclear(get_env(NULL), free);
	ft_lstclear(get_list(NULL), free);
	ft_lstclear(get_list2(NULL), free_cmd);
	ft_free("a", (char ***)get_void(NULL));
	close(get_fd_heredoc(-1));
	close(get_fd_heredoc(-1));
	rl_clear_history();
	exit(130);
}
