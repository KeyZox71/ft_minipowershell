/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:20:22 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/22 14:07:50 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

/**
 * @brief				function to fill an env struct from an array
 *
 * @param env_d			env values as an array
 * @param env			pointer to the env struct we will fill
 *
 * @return (int)		0 if everything goes well, 1 on error
 */
int		env_init(char **env_d, t_env *env);

/**
 * @brief				get value of an env
 *
 * @param name			name of the variable you want
 * @param env			the env struct
 *
 * @return (char *)		content of the variable, NULL if doesn't exist
 */
char	*env_get_value(char *name, t_env *env);

/**
 * @brief				get value of an env
 *
 * @param name			name of the variable you want
 * @param env			the env struct
 * @param n				length of the name
 *
 * @return (char *)		content of the variable, NULL if doesn't exist
 */
char	*env_getn_value(char *name, t_env *env, int n);

/**
 * @brief				get an array from the env struct
 *
 * @param env			the env struct you want to convert
 *
 * @return (char **)	the array, or NULL on error
 */
char	**env_get(t_env *env);

/**
 * @brief				append content at the end of an env variable
 *
 * @param name			name of the variable that will be changed
 * @param content		content that will be append
 * @param env			the env struct that will be affected
 *
 * @return (int)		0 if everything goes well, -1 on error
 */
int		env_append(char *name, char *content, t_env *env);

/**
 * @brief				replace the content of an env variable
 *
 * @param name			name of the variable that will be changed
 * @param content		content that you want to add
 * @param env			the env struct that will be affected
 *
 * @return (int)		0 if everything goes well, -1 on error
 */
int		env_edit(char *name, char *content, t_env *env);

/**
 * @brief				delete an entry in the env struct
 *
 * @param name			name of the variable that will be deleted
 * @param env			the env struct that will be affected
 *
 * @return (int)		0 if everything goes well, -1 on error
 */
int		env_delete(char *name, t_env *env);

// theses are literally the linked-list functions but for env
void	ft_envadd_back(t_env **env, t_env *new);
void	ft_envadd_front(t_env **lst, t_env *new);
void	ft_envclear(t_env **lst, void (*del)(void *));
void	ft_envdelone(t_env *lst, void (*del)(void *));
t_env	*ft_envlast(t_env *env);
t_env	*ft_envnew(char *name, char *content);
unsigned int	ft_envsize(t_env *lst);

/**
 * @brief				DEBUG FUNC : print the actual state of the env struct
 *
 * @param env			the env struct that will be printed
 *
 * @return (void)
 */
void	ft_envprint(t_env *env);

#endif
