/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:27:55 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/15 20:58:08 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exec(t_env *env, char **env_array)
{
	rl_clear_history();
	ft_envclear(&env, free);
	ft_lstclear(get_list(NULL), &free_cmd);
	if (env_array)
		ft_free("a", &env_array);
}
