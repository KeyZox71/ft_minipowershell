/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:05:18 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/29 19:39:01 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "env.h"

# define PATH_MAX_LEN 4096

void	ft_pwd(void);
void	ft_cd(t_env *env, char *args);
void	ft_echo(char **args);
char	*ret_cwd(void);

void	ft_env(t_env *env);
void	ft_unset(char *arg, t_env *env);
void	ft_export(char **args, t_env *env);

#endif
