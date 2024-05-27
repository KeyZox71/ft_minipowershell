/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:42:00 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/27 12:52:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*get_pwd(void)
{
	char	*pwd;
	char	*home;

	pwd = getenv("PWD");
	if (!pwd)
		return (NULL);
	home = getenv("HOME");
	if (!pwd)
		return (NULL);
	if (!ft_strncmp(pwd, home, ft_strlen(home)))
	{
		pwd += ft_strlen(home);
		pwd = ft_strjoin("~", pwd);
		if (!pwd)
			return (NULL);
		return (pwd);
	}
	return (ft_strdup(pwd));
}
