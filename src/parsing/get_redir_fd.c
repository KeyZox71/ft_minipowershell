/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:48:41 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/30 17:47:43 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "tokenizer.h"
#include "execution.h"
#include <fcntl.h>
#include "libft.h"

t_cmd	*get_redir_fd(void *content)
{
	t_token			*token;
	t_list			*tmp;
	t_redirection	*tmp_redir;
	t_redirection	out;
	t_redirection	in;
	t_cmd			*cmd;

	token = (t_token *)content;
	tmp = token->redirection;
	cmd = NULL;
	out.sign = INFILE;
	in.sign = OUTFILE;
	cmd = ft_calloc(sizeof(t_cmd), 1);
	while (tmp)
	{
		tmp_redir = (t_redirection *)tmp->content;
		if (tmp_redir->sign == (t_redirection_sign)HEREDOC)
		{
			in.file_name = NULL;
			in.sign = HEREDOC;
			close(cmd->infile);
			cmd->infile = ft_heredoc(tmp_redir->file_name);
		}
		else if (tmp_redir->sign == INFILE)
		{
			in.sign = INFILE;
			in.file_name = tmp_redir->file_name;
		}
		else
		{
			out.sign = tmp_redir->sign;
			out.file_name = tmp_redir->file_name;
		}
		tmp = tmp->next;
	}
	if (in.sign == OUTFILE)
		cmd->infile = STDIN_FILENO;
	else if (in.sign == INFILE)
	{
		cmd->infile = open(in.file_name, O_RDONLY);
		ft_putendl_fd(in.file_name, STDOUT_FILENO);
	}
	if (out.sign == INFILE)
		cmd->outfile = STDOUT_FILENO;
	else if (out.sign == OUTFILE)
		cmd->outfile = open(out.file_name, O_CREAT | O_TRUNC | O_WRONLY);
	else if (out.sign == OUT_APPEND)
		cmd->outfile = open(out.file_name, O_CREAT | O_APPEND | O_WRONLY);
	return (cmd);
}
