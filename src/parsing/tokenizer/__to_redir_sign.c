/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __to_redir_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:06:40 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/30 17:27:57 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_redir_sign	__to_redir_sign(char *redir_sign)
{
	if (redir_sign[0] == '<' && redir_sign[1] != '<')
		return (INFILE);
	else if (redir_sign[0] == '<' && redir_sign[1] == '<')
		return (HEREDOC);
	else if (redir_sign[0] == '>' && redir_sign[1] == '>')
		return (OUT_APPEND);
	else if (redir_sign[0] == '>' && redir_sign[1] != '>')
		return (OUTFILE);
	return (0);
}
