/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __to_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:06:15 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/04 12:53:17 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"
#include <stdio.h>
#include "parsing.h"

size_t	__cpy_arg(char *dst, char *src);
size_t	__get_len_arg(char *s);
char	*format_quotes_string(char *cmd);

char	*__redir_filename_cpy(char *redir_s)
{
	char	*tmp;

	tmp = ft_calloc(__get_len_arg(redir_s) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	__cpy_arg(tmp, redir_s);
	tmp = format_quotes_string(tmp);
	return (tmp);
}

t_redirection	*__to_redir(char *redir_s)
{
	t_redirection	*redir;

	redir = ft_calloc(sizeof(t_redirection), 1);
	if (!redir)
		return (NULL);
	redir->sign = __to_redir_sign(redir_s);
	redir->file_name = NULL;
	if (redir->sign == OUT_APPEND || redir->sign == HEREDOC)
		redir_s += 2;
	else
		redir_s++;
	while (*redir_s && ft_isspace(*redir_s))
		redir_s++;
	redir->file_name = __redir_filename_cpy(redir_s);
	return (redir);
}
