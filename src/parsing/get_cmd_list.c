/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:47:13 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/30 17:28:40 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

t_list	*get_cmd_list(t_list *list)
{
	t_list	*tmp;
	t_list	*cmd_list;

	tmp = list;
	cmd_list = NULL;
	while (tmp)
	{
		ft_lstadd_back(&cmd_list, ft_lstnew(get_redir_fd(tmp->content)));
		tmp = tmp->next;
	}
	return (cmd_list);
}
