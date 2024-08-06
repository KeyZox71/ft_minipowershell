/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:59:34 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/05 16:28:43 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error_msg.h"
#include <stdio.h>

char	*go_to_nxt_quote(char *rl, t_quote quote_type)
{
	while (*rl && __is_quote(*rl) != quote_type)
		rl++;
	return (rl);
}

bool	watch_quote(char *rl)
{
	char	*tmp;

	tmp = rl;
	while (*tmp)
	{
		if (*tmp == DOUBLE || *tmp == SINGLE)
		{
			tmp = go_to_nxt_quote(tmp + 1, __is_quote(*tmp));
			if (!*tmp)
				return (true);
		}
		tmp++;
	}
	return (false);
}

bool	check_quote(char *readline)
{
	if (watch_quote(readline))
		return (send_error_parsing("quote not closed"));
	return (false);
}
