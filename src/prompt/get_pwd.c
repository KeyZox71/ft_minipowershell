/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:42:00 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/18 16:57:47 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "env.h"

char	*_format_pwd(char *pwd, char *home)
{
	char	*tmp;

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

char	*get_pwd(t_env *env)
{
	char	*pwd;
	char	*home;

	pwd = env_get_value("PWD", env);
	if (!pwd)
		return (NULL);
	home = env_get_value("HOME", env);
	if (!home)
	{
		free(pwd);
		return (NULL);
	}
	return (_format_pwd(pwd, home));
}
