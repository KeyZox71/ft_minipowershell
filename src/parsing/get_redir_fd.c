/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:48:41 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/04 15:35:30 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "tokenizer.h"
#include "execution.h"
#include <fcntl.h>
#include "libft.h"

t_cmd	*get_redir_fd(void *content)
{
	t_token				*token;
	t_list				*tmp;
	t_redirection		*tmp_redir;
	t_redirection_sign	out;
	t_redirection_sign	in;
	t_cmd				*cmd;

	token = (t_token *)content;
	tmp = token->redirection;
	cmd = NULL;
	out = INFILE;
	in = OUTFILE;
	cmd = ft_calloc(sizeof(t_cmd), 1);
	while (tmp)
	{
		tmp_redir = (t_redirection *)tmp->content;
		if (tmp_redir->sign == (t_redirection_sign)HEREDOC)
		{
			if (cmd->infile != 0)
				close(cmd->infile);
			in = HEREDOC;
			cmd->infile = ft_heredoc(tmp_redir->file_name);
		}
		else if (tmp_redir->sign == INFILE)
		{
			if (cmd->infile != 0)
				close(cmd->infile);
			cmd->infile = open(tmp_redir->file_name, O_RDONLY);
			in = INFILE;
		}
		else if (tmp_redir->sign == OUTFILE)
		{
			if (cmd->infile != 0)
				close(cmd->outfile);
			out = OUTFILE;
			cmd->outfile = open(tmp_redir->file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		}
		else if (tmp_redir->sign == OUT_APPEND)
		{
			if (cmd->infile != 0)
				close(cmd->outfile);
			out = OUT_APPEND;
			cmd->outfile = open(tmp_redir->file_name, O_CREAT | O_APPEND | O_WRONLY, 0644);
		}
		tmp = tmp->next;
	}
	if (in == OUTFILE)
		cmd->infile = STDIN_FILENO;
	if (out == INFILE)
		cmd->outfile = STDOUT_FILENO;
	cmd = split_cmd(token->argv, cmd);
	return (cmd);
}
