/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:42:00 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/30 15:41:46 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "env.h"

char	*get_pwd(t_env env)
{
	char	*pwd;
	char	*home;

	pwd = env_get_value("PWD", &env);
	if (!pwd)
		return (NULL);
	home = env_get_value("HOME", &env);
	if (!pwd)
		return (NULL);
	if (!ft_strncmp(pwd, home, ft_strlen(home) - 1))
	{
		pwd += ft_strlen(home);
		pwd = ft_strjoin("~", pwd);
		if (!pwd)
			return (NULL);
		return (pwd);
	}
	return (ft_strdup(pwd));
}
