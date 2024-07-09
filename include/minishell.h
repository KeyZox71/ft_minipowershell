/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:38:51 by mmoussou          #+#    #+#             */
/*   Updated: 2024/05/06 20:30:42 by mmoussou         ###   ########.fr       */
/*   Updated: 2024/05/03 10:24:15 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <signal.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <stdbool.h>
# include "libft.h"

# include "error_msg.h"
# include "env.h"
# include "prompt.h"
# include "parsing.h"
# include "execution.h"

void	free_redir(void *redir_v);
void	free_token(void *token_v);
void	free_cmd(void *content);

t_env	**get_env(t_env **env);
t_list	**get_list(t_list **list);
t_list	**get_list2(t_list **list);

#endif
