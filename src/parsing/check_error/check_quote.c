/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:59:34 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/15 18:16:52 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error_msg.h"
#include "tokenizer.h"

size_t	count_quote(char *readline, t_quote type)
{
	char	*tmp;
	size_t	count;

	tmp = readline;
	count = 0;
	while (*tmp)
	{
		if (*tmp == type)
			count += search_for_next_quote(tmp, type) - tmp;
		tmp++;
	}
	return (count);
}

bool	check_quote(char *readline)
{
	size_t	count;

	count = count_quote(readline, DOUBLE);
	if (count % 2)
		return (send_error_parsing("double quote not closed"));
	count = count_quote(readline, SINGLE);
	if (count % 2)
		return (send_error_parsing("single quote not closed"));
	return (false);
}
