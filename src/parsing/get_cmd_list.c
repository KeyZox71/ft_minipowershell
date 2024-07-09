/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:47:13 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/10 01:12:52 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "minishell.h"

t_list	*get_cmd_list(t_list *list)
{
	t_list	*tmp;
	t_list	*cmd_list;

	tmp = list;
	cmd_list = malloc(sizeof(t_list));
	get_list2(&cmd_list);
	cmd_list->next = NULL;
	cmd_list->content = get_redir_fd(tmp->content);
	tmp = tmp->next;
	while (tmp)
	{
		ft_lstadd_back(&cmd_list, ft_lstnew(get_redir_fd(tmp->content)));
		tmp = tmp->next;
	}
	return (cmd_list);
}
