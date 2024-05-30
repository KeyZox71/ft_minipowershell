/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:17:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/30 12:52:51 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include "parsing.h"
#include "error_msg.h"

void	check_redir(t_list *redir, char **argv)
{
	t_list			*tmp;
	t_redirection	*tmp_redir;

	tmp = redir;
	while(tmp)
	{
		tmp_redir = tmp->content;
		if (tmp_redir->sign == HEREDOC && \
				!((t_redirection *)(tmp->content))->file_name)
			send_error(ERROR_NO_EOF, argv);
		if (!((t_redirection *)(tmp->content))->file_name)
			send_error(ERROR_NO_REDIR, argv);
		tmp = tmp->next;
	}
}
