/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:52:22 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/03 16:17:02 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include <stdbool.h>
#include "error_msg.h"

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
			tmp += strlen_till_end_char(tmp + 1, ' ') + 1;
			if (!*tmp)
				return (send_error_parsing("No command after pipe"));
		}
		tmp++;
	}
	return (false);
}
