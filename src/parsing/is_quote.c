/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:32:35 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/29 13:32:50 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_quote	__is_quote(char c)
{
	if (c == SINGLE)
		return (SINGLE);
	if (c == DOUBLE)
		return (DOUBLE);
	return (FALSE);
}
