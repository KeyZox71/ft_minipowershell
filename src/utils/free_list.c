/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:10:35 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/04 16:58:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h" 

void	free_redir(void *redir_v)
{
	t_redirection	*redir;

	redir = redir_v;
	free(redir->file_name);
	free(redir);
}

void	free_token(void *token_v)
{
	t_token	*token;

	token = token_v;
	if (token->argv)
		free(token->argv);
	if (token->redirection)
		ft_lstclear(&(token->redirection), free_redir);
	if (token)
		free(token);
}

void	free_cmd(void *content)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)content;
	if (!cmd)
		return ;
	if (cmd->infile > 1)
		close(cmd->infile);
	if (cmd->outfile > 1)
		close(cmd->outfile);
	if (cmd->cmd)
		free(cmd->cmd);
	if (cmd->argv)
		ft_free("a", &(cmd->argv));
	if (cmd)
		free(cmd);
}
