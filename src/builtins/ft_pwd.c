/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:02:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/19 11:40:24 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include "env.h"
#include "libft.h"
#include "builtins.h"

void	ft_pwd(void)
{
	char	*pwd;

	pwd = ret_cwd();
	ft_putendl_fd(pwd, STDOUT_FILENO);
	get_exit_code(0);
}
