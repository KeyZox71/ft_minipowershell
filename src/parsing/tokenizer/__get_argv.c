/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __get_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:30:31 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/06 15:24:51 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	__get_size_argv(char **content)
{
	size_t	size;

	size = 0;
	while (content && *content)
	{
		if (__to_redir_sign(*content) != ERROR)
			content++;
		else
			size++;
		content++;
	}
	return (size);
}

char	**__get_argv(char **content)
{
	char	**argv;
	char	**start;

	if (!content || !*content)
		return (NULL);
	argv = ft_calloc(sizeof(char *), __get_size_argv(content) + 1);
	start = argv;
	while (content && *content)
	{
		if (__to_redir_sign(*content) != ERROR)
		{
			content += 2;
			free(*(content - 1));
			free(*(content - 2));
		}
		else
		{
			*argv = *content;
			argv++;
			content++;
		}
	}
	argv = NULL;
	return (start);
}
