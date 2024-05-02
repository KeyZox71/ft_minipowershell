/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:42:00 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/02 15:49:42 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*get_pwd(void)
{
	char	*pwd;
	char	*home;

	pwd = getenv("PWD");
	home = getenv("HOME");
	if (!ft_strncmp(pwd, home, ft_strlen(home)))
		pwd += ft_strlen(home);
	pwd = ft_strjoin("~", pwd);
	return (pwd);
}
