/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:17:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/30 13:49:21 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "parsing.h"
#include "error_msg.h"

bool	check_redir(t_list *redir)
{
	t_list			*tmp;
	t_redirection	*tmp_redir;

	tmp = redir;
	while (tmp)
	{
		tmp_redir = tmp->content;
		if (tmp_redir->sign == HEREDOC && \
				!((t_redirection *)(tmp->content))->file_name)
			return (send_error_parsing(ERROR_NO_EOF));
		if (!((t_redirection *)(tmp->content))->file_name)
			return (send_error_parsing(ERROR_NO_REDIR));
		tmp = tmp->next;
	}
	return (false);
}
