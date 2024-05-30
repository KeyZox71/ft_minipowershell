/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:00:32 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/30 16:31:04 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

/*t_cmd	*split_cmd(char *cmd_av)
{
	char	**split;
	char	**tmp_split;
	t_cmd	*cmd;

	split = ft_split(cmd_av, 32);
	tmp_split = split;
	cmd = ft_calloc(sizeof(t_cmd), 1);
	cmd->cmd = ft_strdup(*tmp_split);
	cmd->argv = tmp_split;
	return (cmd);
}*/
