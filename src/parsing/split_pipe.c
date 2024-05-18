/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:26:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/18 17:12:42 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

t_list	*split_pipe(char *readline)
{
	char	**split;
	char	**tmp;
	t_list	*list;

	split = ft_split(readline, '|');
	tmp = split;
	if (!*(split+1))
		return (ft_lstnew((void *)readline));
	list = NULL;
	while (tmp && *tmp)
	{
		ft_lstadd_back(&list, ft_lstnew((void *)(*tmp)));
		tmp++;
	}
	free(split);
	return (list);
}
