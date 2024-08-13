/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __to_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:19:35 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/13 16:09:24 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*__get_redir(char **content)
{
	t_list			*list;
	t_redir_sign	sign;
	t_list			*tmp;

	list = NULL;
	while (content && *content)
	{
		sign = __to_redir_sign(*content);
		if (sign == HEREDOC)
		{
			tmp = ft_lstnew(__open_heredoc(*(content + 1), list));
			ft_lstadd_back(&list, tmp);
			if (((t_redir *)tmp->content)->sign == ERROR)
				return (list);
		}
		else if (sign != ERROR)
			ft_lstadd_back(&list, ft_lstnew(__to_redir(*(content + 1), sign)));
		content++;
	}
	return (list);
}

void	*clear_all_cmd(char **content, t_list *redir)
{
	ft_lstclear(&redir, free_redir);
	ft_free("a", &content);
	return (NULL);
}

t_cmd	*return_err_cmd(char **content, t_list *redir)
{
	t_cmd	*cmd;

	cmd = ft_calloc(sizeof(t_cmd), 1);
	if (!cmd)
		return (clear_all_cmd(content, redir));
	cmd->infile = -1;
	cmd->outfile = -1;
	cmd->cmd = NULL;
	cmd->argv = NULL;
	ft_free("a", &content);
	ft_lstclear(&redir, free_redir);
	return (cmd);
}

t_cmd	*__to_cmd(char **content)
{
	t_list	*redir;
	t_cmd	*cmd;

	if (!content)
		return (NULL);
	if (!*content)
	{
		free(content);
		return (NULL);
	}
	format_quotes(content);
	get_void(&content);
	redir = __get_redir(content);
	if (check_redir_single(redir))
		return (return_err_cmd(content, redir));
	cmd = ft_calloc(sizeof(t_cmd), 1);
	if (!cmd)
		return (clear_all_cmd(content, redir));
	__get_fd(redir, cmd);
	cmd->argv = __get_argv(content);
	free(content);
	cmd->cmd = ft_strdup(cmd->argv[0]);
	ft_lstclear(&redir, free);
	return (cmd);
}
