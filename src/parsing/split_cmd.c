/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:00:32 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/01 17:39:20 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

t_cmd	*split_cmd(char *cmd_av, t_cmd *cmd)
{
	char	**split;

	cmd->argv = NULL;
	cmd->cmd = NULL;
	split = split_argv(cmd_av);
	if (!split)
	{
		cmd->argv = NULL;
		cmd->cmd = NULL;
		return (cmd);
	}
	cmd->argv = split;
	cmd->cmd = ft_strdup(*split);
	if (!cmd->cmd)
		return (cmd);
	return (cmd);
}
