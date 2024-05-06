/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:20:22 by mmoussou          #+#    #+#             */
/*   Updated: 2024/05/06 20:29:58 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

int		env_init(char **env_d, t_env *env);
void	env_print(t_env *env);
char	**env_get(t_env *env);
int		env_append(char *name, char *content, t_env *env);
int		env_edit(char *name, char *content, t_env *env);
int		env_delete(char *name, t_env *env);

void	ft_envadd_back(t_env **env, t_env *new);
void	ft_envadd_front(t_env **lst, t_env *new);
void	ft_envclear(t_env **lst, void (*del)(void *));
void	ft_envdelone(t_env *lst, void (*del)(void *));
t_env	*ft_envlast(t_env *env);
t_env	*ft_envnew(char *name, char *content);
uint	ft_envsize(t_env *lst);

#endif
