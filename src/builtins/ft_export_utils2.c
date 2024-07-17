/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:29:28 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/17 01:29:58 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

void	ft_arraysort(char **env)
{
	char	*tmp;
	int		i;
	int		y;

	i = ft_arraylen(env);
	while (i)
	{
		y = 0;
		while (y < i - 1)
		{
			if (ft_strcmp(env[y], env[y + 1]) > 0)
			{
				tmp = env[y];
				env[y] = env[y + 1];
				env[y + 1] = tmp;
			}
			y++;
		}
		i--;
	}
}
