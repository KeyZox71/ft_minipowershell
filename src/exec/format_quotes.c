/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:50:52 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/14 17:39:18 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*format_quotes_string(char *cmd)
{
	if (!cmd)
		return (NULL);
	if (*cmd == DOUBLE || *cmd == SINGLE)
		ft_strlcpy(cmd, cmd + 1, ft_strlen(cmd) - 1);
	return (cmd);
}

int	format_quotes_cmd(t_cmd *cmd)
{
	uint	i;

	if (!cmd)
		return (-1);
	cmd->cmd = format_quotes_string(cmd->cmd);
	i = 0;
	while (cmd->argv[i])
	{
		cmd->argv[i] = format_quotes_string(cmd->argv[i]);
		i++;
	}
	return (0);
}

int	format_quotes(t_list *list_cmd)
{
	if (!list_cmd)
		return (0);
	while (list_cmd)
	{
		if (format_quotes_cmd(list_cmd->content))
			return (-1);
		list_cmd = list_cmd->next;
	}
	return (0);
}
