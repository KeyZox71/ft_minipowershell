/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:42:00 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/09 14:36:05 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "env.h"

char	*get_pwd(t_env *env)
{
	char	*pwd;
	char	*home;
	char	*tmp;

	pwd = env_get_value("PWD", env);
	if (!pwd)
		return (NULL);
	home = env_get_value("HOME", env);
	if (!home)
		return (NULL);
	if (!ft_strncmp(pwd, home, ft_strlen(home) - 1))
	{
		tmp = pwd;
		tmp += ft_strlen(home);
		free(home);
		tmp = ft_strjoin("~", tmp);
		free(pwd);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	free(home);
	return (pwd);
}
