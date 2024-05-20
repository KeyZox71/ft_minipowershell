/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:20:22 by mmoussou          #+#    #+#             */
/*   Updated: 2024/05/21 00:20:49 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

int		get_path(char *path);

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

/**
 * @brief				spawn a heredoc
 *
 * @param delimiter		a string representing the delimiter of the heredoc
 *
 * @return (int)		fd of a file containing the user's input, or -1 on error
 */
int		ft_heredoc(char *delimiter);

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
 * @brief				DEBUG FUNC : print the actual state of the env struct
 *
 * @param env			the env struct that will be printed
 *
 * @return (void)
 */
void	env_print(t_env *env);

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
uint	ft_envsize(t_env *lst);

#endif
