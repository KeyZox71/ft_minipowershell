/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:40:13 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/06 16:51:48 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"
#include "parsing.h"
#include "error_msg.h"

bool	is_chevron(int c)
{
	if (c == '<' || c == '>')
		return (true);
	return (false);
}

bool	check_triple(char *chevron)
{
	if (is_chevron(*chevron) && is_chevron(*(chevron + 1)) \
			&& is_chevron(*(chevron + 2)))
		return (true);
	return (false);
}

bool	check_if_file(char *readline)
{
	char	*tmp;

	tmp = readline;
	if (is_chevron(*tmp))
	{
		while (*tmp && is_chevron(*tmp))
			tmp++;
		while (*tmp && ft_isspace(*tmp))
			tmp++;
		if (!*tmp)
			return (true);
	}
	return (false);
}

bool	check_syntax(char *readline)
{
	char	*tmp;

	tmp = readline;
	while (*tmp)
	{
		if (check_triple(tmp))
			return (send_error_parsing(ERROR_SYNTAX));
		if (check_if_file(tmp))
			return (send_error_parsing(ERROR_SYNTAX));
		tmp++;
	}
	return (false);
}
