/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __to_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:05:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/23 20:12:03 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_redirection_sign	__to_redir_sign(char *redir_sign)
{
	if (redir_sign[0] == '<' && redir_sign[1] != '<')
		return (INFILE);
	else if (redir_sign[0] == '<' && redir_sign[1] == '<')
		return (HEREDOC);
	else if (redir_sign[0] == '>' && redir_sign[1] != '>')
		return (OUT_APPEND);
	else if (redir_sign[0] == '>' && redir_sign[1] != '>')
		return (OUTFILE);
	return (0);
}

t_redirection	*__to_redir(char	*redir_s)
{
	char			*tmp;
	t_redirection	*redir;
	char			*start_of_filename;
	char			*filename;

	redir = ft_calloc(sizeof(t_redirection), 1);
	redir->sign = __to_redir_sign(redir_s);
	tmp = redir_s;
	if (!redir->sign)
		return (NULL);
	if (redir->sign % 2)
		tmp++;
	else
		tmp += 2;
	while (*tmp && *tmp != ' ')
		tmp++;
	start_of_filename = tmp;
	while (*tmp && !ft_isalnum(*tmp))
		tmp++;
	filename = ft_calloc(tmp - start_of_filename + 1, sizeof(char));
	ft_strlcpy(filename, start_of_filename, (tmp - start_of_filename));
	redir->file_name = filename;
	return (redir);
}

t_token	*__to_token(char *cmd)
{
	char			*tmp;
	t_token			*token;
	t_redirection	*tmp_redir;
	char			*argv;

	tmp = cmd;
	argv = NULL;
	token = ft_calloc(sizeof(t_token), 1);
	while (*tmp)
	{
		if (*tmp == '<' || *tmp == '>')
		{
			tmp_redir = __to_redir(tmp);
			ft_lstadd_back(&(token->redirection), ft_lstnew((void *)&tmp_redir));
		}
		else
			ft_strjoin_free_s1(argv, &(*tmp));
		tmp++;
	}
	return (token);
}
