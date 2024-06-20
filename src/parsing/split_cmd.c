/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:00:32 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/18 12:56:43 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

t_cmd	*split_cmd(char *cmd_av, t_cmd *cmd)
{
	char	**split;

	split = ft_split(cmd_av, ' ');
	cmd->cmd = ft_strdup(*split);
	cmd->argv = split;
	return (cmd);
}
