/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:07:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/24 18:48:11 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"

char	*__get_parent_directory(char *pwd)
{
	char	*tmp;
	char	*dir;
	char	*parent;

	tmp = pwd;
	while (*tmp)
	{
		if (*tmp == '/')
			dir = tmp;
		tmp++;
	}
	parent = ft_calloc(dir - pwd + 1, sizeof(char));
	ft_strlcpy(parent, pwd, dir - pwd + 1);
	free(pwd);
	return (parent);
}

char	*ret_cwd(void)
{
	
}

void	ft_cd(t_env *env, char *args)
{
	char	*new_pwd;

	new_pwd = NULL;
	pwd = getcwd();
	ft_putendl_fd(args, STDOUT_FILENO);
	ft_putendl_fd(env_get_value("PWD", env), STDOUT_FILENO);
	if (!args)
		new_pwd = env_get_value("HOME", env);
	else if (args[0] == '/')
		new_pwd = ft_strdup(args);
	else if (is_str(args, ".."))
		new_pwd = __get_parent_directory(env_get_value("PWD", env));
	ret = chdir(new_pwd);
	if (ret == -1)
	{
	}
	env_edit("PWD", new_pwd, env);
	free(args);
	ft_putendl_fd(new_pwd, STDOUT_FILENO);
}
