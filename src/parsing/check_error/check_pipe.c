/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:52:22 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/04 13:45:18 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdbool.h>
#include "error_msg.h"
#include <stdio.h>

size_t	strlen_till_end_char(char *s, int c)
{
	char	*tmp;

	tmp = s;
	while (*tmp && *tmp == c)
		tmp++;
	return (tmp - s);
}

bool	check_pipe(char *readline)
{
	char	*tmp;

	tmp = readline;
	while (*tmp)
	{
		if (*tmp == '|' && is_inquote(readline, tmp - readline) == FALSE)
		{
			if (!*(tmp + 1) || *(tmp + 1) == '|')
				return (send_error_parsing("No command after pipe"));
			tmp++;
			while (*tmp && ft_isspace(*tmp))
				tmp++;
			if ((!tmp && !*tmp) || *tmp == '|')
				return (send_error_parsing("No command after pipe"));
		}
		tmp++;
	}
	return (false);
}
