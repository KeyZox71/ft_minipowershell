/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:28:36 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/15 16:07:23 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

void	free_exit(t_env *env, char **env_array)
{
	int	i;

	i = 3;
	while (i < 1024)
	{
		close(i);
		i++;
	}
	rl_clear_history();
	ft_envclear(&env, free);
	ft_lstclear(get_list(NULL), &free_cmd);
	ft_free("a", &env_array);
}
