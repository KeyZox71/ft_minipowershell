/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:34:19 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/14 15:34:16 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "parsing.h"
#include "error_msg.h"

bool	check_file_name(t_list *redir)
{
	while (redir)
	{
		if (!((t_redirection *)redir->content)->file_name)
			return (true);
		redir = redir->next;
	}
	return (false);
}

bool	check_argv(t_list *token)
{
	t_list	*tmp;

	tmp = token;
	while (tmp)
	{
		if (!((t_token *)tmp->content)->argv)
			return (send_error_parsing(ERROR_NO_CMD));
		if (check_file_name(((t_token *)tmp->content)->redirection))
			return (send_error_parsing(ERROR_NO_FILE));
		tmp = tmp->next;
	}
	return (false);
}
