/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:02:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/24 12:33:50 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "env.h"
#include "libft.h"

void	ft_pwd(t_env *env)
{
	char	*pwd;

	pwd = env_get_value("PWD", env);
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
}
