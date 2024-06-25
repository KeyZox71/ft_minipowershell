/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:07:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/25 15:03:15 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env.h"
#include "libft.h"
#include "builtins.h"

char	*__get_parent_directory(char *pwd)
{
	char	*tmp;
	char	*dir;
	//char	*parent;

	tmp = pwd;
	while (*tmp)
	{
		if (*tmp == '/')
			dir = tmp;
		tmp++;
	}
	//parent = ft_calloc(dir - pwd + 1, sizeof(char));
	ft_strlcpy(pwd, pwd, dir - pwd + 1);
	return (pwd);
}

char	*__relative_path(char *args, char *pwd)
{
	char	**path;
	char	**tmp;
	char	*new_path;

	path = ft_split(args, '/');
	tmp = path;
	new_path = ft_strdup(pwd);
	if (!new_path)
		return (NULL);
	while (*tmp)
	{
		if (is_str(*tmp, ".."))
			new_path = __get_parent_directory(new_path);
		else if (*tmp)
		{
			ft_strlcat(new_path, "/", ft_strlen(new_path) + 2);
			ft_strlcat(new_path, *tmp, ft_strlen(new_path) + ft_strlen(*tmp) + 1);
		}
		tmp++;
	}
	return (new_path);
}

void	ft_cd(t_env *env, char *args)
{
	char	*pwd;
	char	*new_pwd;
	int		ret;

	new_pwd = NULL;
	pwd = ret_cwd();
	ft_putendl_fd(env_get_value("OLDPWD", env), STDOUT_FILENO);
	if (!args)
		new_pwd = env_get_value("HOME", env);
	else if (args[0] == '/')
		new_pwd = ft_strdup(args);
	else if (args[0] == '-')
		new_pwd = env_get_value("OLDPWD", env);
	else
		new_pwd = __relative_path(args, pwd);
	ret = chdir(new_pwd);
	if (ret == -1)
		return ;
	env_edit("PWD", new_pwd, env);
	env_edit("OLDPWD", ft_strdup(pwd), env);
	free(args);
}
