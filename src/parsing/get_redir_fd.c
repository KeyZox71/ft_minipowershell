/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:48:41 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/30 17:17:13 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "tokenizer.h"
#include "execution.h"
#include <fcntl.h>
#include "minishell.h"
#include <stdio.h>
#include "libft.h"

t_cmd	*get_redir_fd(void *content, t_list *tmp)
{
	t_redir_sign	sign[2];
	t_cmd			*cmd;

	sign[0] = INFILE;
	sign[1] = OUTFILE;
	cmd = ft_calloc(sizeof(t_cmd), 1);
	if (!cmd)
		return (NULL);
	while (tmp)
	{
		open_redir((t_redirection *)tmp->content, cmd, sign);
		if (cmd->infile >= -1 || cmd->outfile == -1)
		{
			if (cmd->infile == -1 || cmd->outfile == -1)
				send_error_parsing(ERROR_NO_FILE);
			free(cmd);
			return (NULL);
		}
		tmp = tmp->next;
	}
	if (sign[0] == INFILE)
		cmd->outfile = STDOUT_FILENO;
	if (sign[1] == OUTFILE)
		cmd->infile = STDIN_FILENO;
	cmd = split_cmd(((t_token *)content)->argv, cmd);
	return (cmd);
}
