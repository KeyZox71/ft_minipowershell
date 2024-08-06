/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:10:35 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/05 23:27:57 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h" 

void	free_redir(void *redir_v)
{
	t_redir	*redir;

	redir = redir_v;
	if (redir->fd > 1)
		close (redir->fd);
	free(redir);
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
