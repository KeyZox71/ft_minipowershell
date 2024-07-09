/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redir_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:48:41 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/09 16:16:27 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "tokenizer.h"
#include "execution.h"
#include <fcntl.h>
#include "minishell.h"
#include <stdio.h>
#include "libft.h"

t_cmd	*get_redir_fd(void *content, t_env *env)
{
	t_list			*tmp;
	t_redir_sign	sign[2];
	t_cmd			*cmd;
	char			*env_varred;

	tmp = ((t_token *)content)->redirection;
	cmd = NULL;
	sign[0] = INFILE;
	sign[1] = OUTFILE;
	cmd = ft_calloc(sizeof(t_cmd), 1);
	while (tmp)
	{
		open_redir((t_redirection *)tmp->content, cmd, sign);
		tmp = tmp->next;
	}
	if (sign[0] == INFILE)
		cmd->outfile = STDOUT_FILENO;
	if (sign[1] == OUTFILE)
		cmd->infile = STDIN_FILENO;
	env_varred = env_var_replace(((t_token *)content)->argv, env);
	cmd = split_cmd(env_varred, cmd);
	free(env_varred);
	return (cmd);
}
