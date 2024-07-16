/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:59:34 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/16 16:15:41 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error_msg.h"
#include "tokenizer.h"
#include <stdio.h>

bool	watch_quote(char *rl)
{
	char	*tmp;

	tmp = rl;
	while (*tmp)
	{
		if (__is_quote(*tmp) != FALSE)
		{
			tmp = search_for_next_quote(tmp + 1, __is_quote(*tmp));
			if (!tmp)
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
