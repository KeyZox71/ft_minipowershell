/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:34:19 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/03 19:07:23 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "parsing.h"
#include "error_msg.h"

bool	check_argv(t_list *token)
{
	t_list	*tmp;

	tmp = token;
	while (tmp)
	{
		if (!((t_token *)tmp->content)->argv)
			return (send_error_parsing(ERROR_NO_CMD));
		tmp = tmp->next;
	}
	return (false);
}
