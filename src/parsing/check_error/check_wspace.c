/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:18:19 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/30 14:36:47 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error_msg.h"

bool	check_wspace(char *readline)
{
	while (*readline && ft_isspace(*readline))
		readline++;
	if (!*readline)
		return (send_error_parsing("Only white space in line"));
	return (false);
}
