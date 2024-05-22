/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __split_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:01:25 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/22 11:42:47 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

t_list	*__split_pipe(char *readline)
{
	char	*tmp;
	t_list	*pipe;
	char	*start_of_pipe;
	char	*tmp_pipe;

	tmp = readline;
	start_of_pipe = readline;
	pipe = NULL;
	(void)pipe;
	while (*tmp)
	{
		if (*tmp == '|' && is_inquote(readline, (tmp - readline)) == FALSE)
		{
			tmp_pipe = ft_calloc(tmp - start_of_pipe + 1, sizeof(char));
			if (!tmp_pipe)
			{
				ft_lstclear(&pipe, free);
				return (NULL);
			}
			ft_strlcpy(tmp_pipe, start_of_pipe, (tmp - start_of_pipe) + 1);
			ft_lstadd_back(&pipe, ft_lstnew((void *)(tmp_pipe)));
			start_of_pipe = tmp + 1;
		}
		tmp++;
	}
	ft_lstadd_back(&pipe, ft_lstnew((void *)ft_strdup(start_of_pipe)));
	return (pipe);
}
