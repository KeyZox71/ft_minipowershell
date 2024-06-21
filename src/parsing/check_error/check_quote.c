/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:59:34 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/21 12:40:56 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
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
			count++;
		tmp++;
	}
	return (count);
}

void	check_quote(char *readline)
{
	size_t	count;

	count = count_quote(readline, DOUBLE);
	if (count % 2)
	{
		ft_putendl_fd("double quote error", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	count = count_quote(readline, SINGLE);
	if (count % 2)
	{
		ft_putendl_fd("single quote error", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}
