/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:50:52 by mmoussou          #+#    #+#             */
/*   Updated: 2024/08/06 17:02:58 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_char(char *cmd, int i, char c)
{
	if (c == -1)
		c = SINGLE;
	else if (c == -2)
		c = DOUBLE;
	cmd[i] = c;
}

void	copy_until_next(char *cmd, char quote, uint *i, uint *i_offset)
{
	(*i_offset)++;
	(*i)++;
	while (cmd[*i] && cmd[*i] != quote)
	{
		copy_char(cmd, *i - *i_offset, cmd[*i]);
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
			copy_char(cmd, i - i_offset, cmd[i]);
		i++;
	}
	cmd[i - i_offset] = 0;
	return (cmd);
}

void	format_quotes(char **content)
{
	char	**argv;

	argv = content;
	while (argv && *argv)
	{
		*argv = format_quotes_string(*argv);
		argv++;
	}
}
