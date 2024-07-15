/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:07:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/15 16:38:59 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_msg.h"
#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "builtins.h"

void	ft_cd(t_env *env, char *args)
{
	char	*pwd;
	char	*new_pwd;
	int		ret;

	new_pwd = NULL;
	pwd = ft_strdup(ret_cwd());
	if (!args)
		new_pwd = env_get_value("HOME", env);
	else if (args[0] == '-')
		new_pwd = env_get_value("OLDPWD", env);
	else
		new_pwd = ft_strdup(args);
	ret = chdir(new_pwd);
	free(new_pwd);
	if (ret == -1)
	{
		send_error_parsing(ERROR_NO_FILE);
		return ;
	}
	env_edit("PWD", ft_strdup(ret_cwd()), env);
	env_edit("OLDPWD", pwd, env);
}
