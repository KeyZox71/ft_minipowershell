/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:02:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/25 11:31:15 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "env.h"
#include "libft.h"
#include "builtins.h"

void	ft_pwd(void)
{
	char	*pwd;

	pwd = ret_cwd();
	ft_putendl_fd(pwd, STDOUT_FILENO);
}
