/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __open_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 23:31:09 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/06 15:29:13 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "execution.h"
#include <fcntl.h>

t_redir_sign	__to_redir_sign(char *redir_sign)
{
	if (!redir_sign || !*redir_sign)
		return (ERROR);
	else if (!(*redir_sign == '<' || *redir_sign == '>'))
		return (ERROR);
	else if (*redir_sign == '<' && !*(redir_sign + 1))
		return (INFILE);
	else if (*redir_sign == '<' && *(redir_sign + 1) == '<' \
			&& !*(redir_sign + 2))
		return (HEREDOC);
	else if (*redir_sign == '>' && !*(redir_sign + 1))
		return (OUTFILE);
	else if (*redir_sign == '>' && *(redir_sign + 1) == '>' \
			&& !*(redir_sign + 2))
		return (OUT_APPEND);
	return (ERROR);
}

t_redir	*__open_heredoc(char *filename)
{
	int		fd;
	t_redir	*redir;

	if (!filename && !*filename)
		return (NULL);
	fd = ft_heredoc(filename);
	redir = ft_calloc(sizeof(t_redir), 1);
	if (!redir)
	{
		if (fd != -1)
			close(fd);
		return (NULL);
	}
	redir->fd = fd;
	if (fd == -2)
		redir->sign = ERROR;
	else
		redir->sign = HEREDOC;
	return (redir);
}

t_redir	*__to_redir(char *filename, t_redir_sign sign)
{
	t_redir	*redir;
	int		fd;

	if (!filename && !*filename)
		return (NULL);
	fd = -1;
	if (sign == INFILE)
		fd = open(filename, O_RDONLY);
	else if (sign == OUTFILE)
		fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (sign == OUT_APPEND)
		fd = open(filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
	redir = ft_calloc(sizeof(t_redir), 1);
	if (!redir)
	{
		if (fd != 1)
			close(fd);
		return (NULL);
	}
	redir->fd = fd;
	redir->sign = sign;
	return (redir);
}
