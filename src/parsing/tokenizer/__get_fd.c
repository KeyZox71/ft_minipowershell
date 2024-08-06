/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __get_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 23:34:03 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/06 14:15:02 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>

void	__get_fd(t_list *list, t_cmd *cmd)
{
	t_redir	*redir;

	cmd->infile = STDIN_FILENO;
	cmd->outfile = STDOUT_FILENO;
	if (!list)
		return ;
	while (list)
	{
		redir = list->content;
		if (redir->sign < 2)
		{
			if (cmd->infile > 1)
				close (cmd->infile);
			cmd->infile = redir->fd;
		}
		else if (redir->sign >= 2)
		{
			if (cmd->outfile > 1)
				close (cmd->outfile);
			cmd->outfile = redir->fd;
		}
		list = list->next;
	}
}
