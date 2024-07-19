/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:07:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/19 11:38:34 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_msg.h"
#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "builtins.h"

void	change_dir(char *new_pwd, char *pwd, t_env *env)
{
	int		ret;

	ret = chdir(new_pwd);
	free(new_pwd);
	if (ret == -1)
	{
		free(pwd);
		send_error_parsing(ERROR_NO_FILE);
		get_exit_code(1);
		return ;
	}
	env_edit("PWD", ft_strdup(ret_cwd()), env);
	env_edit("OLDPWD", pwd, env);
	get_exit_code(0);
}

void	ft_cd(t_env *env, char *args)
{
	char	*pwd;
	char	*new_pwd;

	new_pwd = NULL;
	pwd = ft_strdup(ret_cwd());
	if (!args)
		new_pwd = env_get_value("HOME", env);
	else if (args[0] == '-')
		new_pwd = env_get_value("OLDPWD", env);
	else
		new_pwd = ft_strdup(args);
	if (!new_pwd)
	{
		free(pwd);
		return ;
	}
	change_dir(new_pwd, pwd, env);
}
