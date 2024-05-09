/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:26:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/08 14:38:33 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

t_list	*split_pipe(char *readline)
{
	//char	*tmp;
	char	*av;
	//char	*cmd_start;
	t_list	*list;

	list = NULL;
	if (!list)
	{
		av = ft_calloc(sizeof(readline), sizeof(char));
		ft_strlcpy(av, readline, ft_strlen(readline));
		ft_lstadd_back(&list, ft_lstnew((void*)split_cmd(av)));
	}
	return (list);
}
