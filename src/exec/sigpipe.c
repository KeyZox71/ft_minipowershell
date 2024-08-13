/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigpipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:23:24 by mmoussou          #+#    #+#             */
/*   Updated: 2024/08/13 18:40:19 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

char	**get_env_arr(char **env)
{
	static char	**ret;

	if (env)
		ret = env;
	return (ret);
}

void	sig_p(int code)
{
	t_env	**env;

	(void) code;
	env = get_env(NULL);
	free_exit(*env, get_env_arr(NULL));
	exit(141);
}
