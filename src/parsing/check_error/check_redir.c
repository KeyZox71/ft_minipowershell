/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:32:21 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/10 17:44:56 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error_msg.h"
#include "minishell.h"

bool	check_redir(t_list *list)
{
	t_list	*tmp;
	t_redir	*redir;

	tmp = list;
	while (tmp)
	{
		redir = (t_redir *)tmp->content;
		if (redir->fd < 0 && redir->fd != -2)
			return (send_error_parsing(ERROR_NO_FILE));
		tmp = tmp->next;
	}
	return (false);
}
