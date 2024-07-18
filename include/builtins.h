/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:05:18 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/18 14:31:31 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "env.h"

# define PATH_MAX_LEN 4096

void			ft_pwd(void);

void			ft_cd(t_env *env, char *args);

void			ft_echo(char **args, int fd);

char			*ret_cwd(void);

void			ft_env(t_env *env);

void			ft_unset(char **args, t_env *env);

void			free_exit(t_env *env, char **env_array);
void			ft_exit(char **argv, int ac, char **env_array, t_env *env);

void			ft_arraysort(char **env);
char			**env_get_list(t_env *env);
void			add_to_env(char *name, char *content, t_env *env);
int				check_export_input(char *input);
unsigned int	ft_arraylen(char **s);
void			ft_export(char **args, t_env *env, int fd);

#endif
