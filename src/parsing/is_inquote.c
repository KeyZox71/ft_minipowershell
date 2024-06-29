/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:06:13 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/29 13:32:54 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include <stdio.h>

char	*search_for_next_quote(char *s, t_quote quote_type)
{
	char	*tmp;

	tmp = s;
	while (*tmp && __is_quote(*tmp) != quote_type)
		tmp++;
	return (tmp);
}

t_quote	is_inquote(char *s, size_t i)
{
	char	*tmp;
	size_t	start_quote;
	t_quote	quote_type;

	start_quote = 0;
	tmp = s;
	quote_type = FALSE;
	while (*tmp)
	{
		if ((size_t)(tmp - s + 1) > i)
			break ;
		if (__is_quote(*tmp) != FALSE)
		{
			start_quote = tmp - s;
			quote_type = __is_quote(*tmp);
			tmp++;
			tmp = search_for_next_quote(tmp, quote_type);
			if ((start_quote < i && (size_t)(tmp - s) > i))
				return (quote_type);
			else if (!*tmp)
				return (NOT_CLOSED);
		}
		tmp++;
	}
	return (FALSE);
}
