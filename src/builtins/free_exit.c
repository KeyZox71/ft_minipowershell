/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:28:36 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/11 11:58:17 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

t_list	**get_list2(t_list **list);

void	free_exit(t_env *env, char **env_array)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		close(i);
		i++;
	}
	rl_clear_history();
	ft_envclear(&env, free);
	ft_lstclear(get_list(NULL), &free_cmd);
	if (env_array)
		ft_free("a", &env_array);
}
