/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:10:35 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/04 20:12:06 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h" 

void	free_redir(void *redir_v)
{
	t_redirection	*redir;

	redir = redir_v;
	free(redir->file_name);
}

void	free_token(void *token_v)
{
	t_token	*token;

	token = token_v;
	free(token->argv);
	ft_lstclear(&(token->redirection), free_redir);
	free(token);
}

void	free_cmd(void *content)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)content;
	free(cmd->cmd);
	ft_free("a", &(cmd->argv));
	free(cmd);
}
