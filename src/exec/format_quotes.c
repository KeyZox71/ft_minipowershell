/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:50:52 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/17 00:37:25 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_until_next(char *cmd, char quote, uint *i, uint *i_offset)
{
	(*i_offset)++;
	(*i)++;
	while (cmd[*i] && cmd[*i] != quote)
	{
		cmd[*i - *i_offset] = cmd[*i];
		(*i)++;
	}
	(*i_offset)++;
}

char	*format_quotes_string(char *cmd)
{
	uint	i;
	uint	i_offset;

	i = 0;
	i_offset = 0;
	while (cmd[i])
	{
		if (cmd[i] == SINGLE)
			copy_until_next(cmd, SINGLE, &i, &i_offset);
		else if (cmd[i] == DOUBLE)
			copy_until_next(cmd, DOUBLE, &i, &i_offset);
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
