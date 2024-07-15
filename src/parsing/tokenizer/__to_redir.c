/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __to_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:06:15 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/15 14:12:50 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_redirection	*__to_redir(char *redir_s)
{
	t_redirection	*redir;
	char			*tmp;

	redir = ft_calloc(sizeof(t_redirection), 1);
	redir->sign = __to_redir_sign(redir_s);
	redir->file_name = NULL;
	if (redir->sign == OUT_APPEND || redir->sign == HEREDOC)
		redir_s += 2;
	else
		redir_s++;
	while (*redir_s && *redir_s == ' ')
		redir_s++;
	tmp = redir_s;
	if (!ft_isalnum(*tmp) && *tmp != '/' && *tmp != '.')
		return (redir);
	while (*tmp && ft_isalnum(*tmp) && *tmp != '/' && *tmp != '.')
		tmp++;
	redir->file_name = ft_calloc(tmp - redir_s + 1, sizeof(char));
	ft_strlcpy(redir->file_name, redir_s, tmp - redir_s + 1);
	redir_s += (tmp - redir_s);
	return (redir);
}
