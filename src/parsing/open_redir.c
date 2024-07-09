/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:56:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/10 01:07:09 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include <fcntl.h>
#include "parsing.h"
#include "execution.h" 
#include <stdio.h>

t_redir_sign	__close_unused_fd(t_cmd *cmd, t_redir_sign sign)
{
	if (cmd->outfile != 0 && sign >= 2)
		close(cmd->outfile);
	else if (cmd->infile != 0 && sign < 2)
		close(cmd->infile);
	return (sign);
}

void	open_redir(t_redirection *redir, t_cmd *cmd, t_redir_sign sign[2])
{
	if (redir->sign == OUTFILE || redir->sign == OUT_APPEND)
		sign[0] = __close_unused_fd(cmd, redir->sign);
	if (redir->sign == INFILE || redir->sign == HEREDOC)
		sign[1] = __close_unused_fd(cmd, redir->sign);
	if (redir->sign == HEREDOC)
		cmd->infile = ft_heredoc(redir->file_name, cmd);
	else if (redir->sign == INFILE)
		cmd->infile = open(redir->file_name, O_RDONLY);
	else if (redir->sign == OUTFILE)
		cmd->outfile = open(redir->file_name, \
			O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (redir->sign == OUT_APPEND)
		cmd->outfile = open(redir->file_name, \
			O_CREAT | O_APPEND | O_WRONLY, 0644);
}
