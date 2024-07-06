/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:50:52 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/06 17:47:53 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*format_quotes_string(char *cmd)
{
	uint	i;
	uint	i_offset;

	i = 0;
	i_offset = 0;
	while (cmd[i])
	{
		if (cmd[i] == SINGLE)
		{
			i_offset++;
			i++;
			while (cmd[i] && cmd[i] != SINGLE)
			{
				cmd[i - i_offset] = cmd[i];
				i++;
			}
			i_offset++;
		}
		else if (cmd[i] == DOUBLE)
		{
			i_offset++;
			i++;
			while (cmd[i] && cmd[i] != DOUBLE)
			{
				cmd[i - i_offset] = cmd[i];
				i++;
			}
			i_offset++;
		}
		else
			cmd[i - i_offset] = cmd[i];
		i++;
	}
	cmd[i - i_offset] = 0;
	return (cmd);
}

int	format_quotes_cmd(t_cmd *cmd)
{
	uint	i;

	format_quotes_string(cmd->cmd);
	i = 0;
	while (cmd->argv[i])
	{
		format_quotes_string(cmd->argv[i]);
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
		format_quotes_cmd(list_cmd->content);
		list_cmd = list_cmd->next;
	}
	return (0);
}
