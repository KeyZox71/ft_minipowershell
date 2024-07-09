/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 01:14:10 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/10 01:16:48 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

int	__open_fd_here(char *path, int mode)
{
	int	fd;

	if (mode > 0)
		fd = open(path, O_RDONLY);
	else
		fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	free(path);
	return (fd);
}

void	ft_lstclear_till_nxt(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!(*lst)->next)
	{
		free(*lst);
		return ;
	}
	if (!lst || !del)
		return ;
	while (lst && *lst && (*lst)->next && del)
	{
		tmp = (*lst)->next;
		if ((*lst)->content)
			ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free(*lst);
}
