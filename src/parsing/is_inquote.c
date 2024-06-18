/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:06:13 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/11 15:26:56 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

t_quote	__is_quote(char c)
{
	if (c == SINGLE) 
		return (SINGLE);
	if (c == DOUBLE)
		return (DOUBLE);
	return (FALSE);
}

char	*search_for_next_quote(char *s, t_quote quote_type)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
	{
		if (__is_quote(*tmp) == quote_type)
			break ;
		tmp++;
	}
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
		if ((size_t)(tmp - s) > i)
			break ;
		if (__is_quote(*tmp) != FALSE)
		{
			start_quote = tmp - s;
			quote_type = __is_quote(*tmp);
			tmp = search_for_next_quote(tmp, quote_type);
			tmp++;
			if (*tmp && (start_quote < i && (size_t)(tmp - s) > i))
				return (quote_type);
			else if (!*tmp)
				return (NOT_CLOSED);
		}
		tmp++;
	}
	return (FALSE);
}
