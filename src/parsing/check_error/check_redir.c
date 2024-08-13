/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:32:21 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/13 16:09:44 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error_msg.h"
#include "minishell.h"

bool	check_redir(t_list *list)
{
	t_list	*tmp;
	t_cmd	*cmd;

	tmp = list;
	while (tmp)
	{
		cmd = (t_cmd *)tmp->content;
		if (cmd->infile == -1 || cmd->outfile == -1)
			return (send_error_parsing(ERROR_NO_FILE));
		tmp = tmp->next;
	}
	return (false);
}

bool	check_redir_single(t_list *list)
{
	t_list	*tmp;
	t_redir	*redir;

	tmp = list;
	while (tmp)
	{
		redir = (t_redir *)tmp->content;
		if (redir->fd < 0 && redir->fd != -2)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
