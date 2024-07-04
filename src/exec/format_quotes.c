/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:50:52 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/04 10:09:03 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

uint	formated_string_size(char *cmd)
{
	uint	i;
	uint	c;

	i = 0;
	c = 0;
	while (cmd[i])
	{
		if (cmd[i] == SINGLE)
		{
			c--;
			while (cmd[i] && cmd[i] != SINGLE)
			{
				i++;
				c++;
			}
			if (!cmd)
				return (c + 1);
			c--;
		}
		if (cmd[i] == DOUBLE)
		{
			c--;
			while (cmd[i] && cmd[i] != DOUBLE)
			{
				i++;
				c++;
			}
			if (!cmd)
				return (c + 1);
			c--;
		}
		i++;
		c++;
	}
	return (c);
}

char	*format_quotes_string(char *cmd)
{
	//char	*new_cmd;
	uint	i;
	uint	i_offset;

	i = formated_string_size(cmd);
	if (i == ft_strlen(cmd))
		return (ft_strdup(cmd));
	/*new_cmd = ft_calloc(sizeof(char), i);
	if (!new_cmd)
		return (NULL);
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == SINGLE)
		{
			i++;
			last_i = i;
			while (cmd[i] && cmd[i] != SINGLE)
				i++;
			ft_strlcat(new_cmd, cmd + last_i, i);
			last_i = i;
		}
		else if (cmd[i] == DOUBLE)
		{
			i++;
			last_i = i;
			while (cmd[i] && cmd[i] != DOUBLE)
				i++;
			ft_strlcat(new_cmd, cmd + last_i, i);
			last_i = i;
		}
		i++;
	}
	ft_strlcat(new_cmd, cmd + last_i, formated_string_size(cmd) + 1);*/
	i = 0;
	i_offset = 0;
	while (cmd[i])
	{
		if (cmd[i] == SINGLE)
		{
			i_offset++;
			while (cmd[i] && cmd[i] != SINGLE)
			{
				cmd[i - i_offset] = cmd[i];
			}
			if (!cmd[i])
			{
				// CANCEL THE OFFSET AND RETURN
				return (cmd);
			}
		}
		else if (cmd[i])
		{
			i_offset++;
		}
		else
			cmd[i - i_offset] = cmd[i];
		i++;
	}
	return (cmd);
}

int	format_quotes_cmd(t_cmd *cmd)
{
	char	*new_cmd;
	uint	i;

	printf("before : %s\n", cmd->cmd);
	new_cmd = format_quotes_string(cmd->cmd);
	if (!new_cmd)
		return (-1);
	free(cmd->cmd);
	cmd->cmd = new_cmd;
	printf("after : %s\n", cmd->cmd);
	i = 0;
	while (cmd->argv[i])
	{
		printf("before : %s\n", cmd->argv[i]);
		new_cmd = format_quotes_string(cmd->argv[i]);
		if (!new_cmd)
			return (-1);
		free(cmd->argv[i]);
		cmd->argv[i] = new_cmd;
		printf("after : %s\n", cmd->argv[i]);
		i++;
	}
	return (0);
}

int	format_quotes(t_list *list_cmd)
{
	printf("aled\n");
	if (!list_cmd)
		return (0);
	while (list_cmd)
	{
		format_quotes_cmd(list_cmd->content);
		list_cmd = list_cmd->next;
	}
	return (0);
}
