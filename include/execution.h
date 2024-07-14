/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:20:22 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/14 15:49:21 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "env.h"
# include "libft.h"
# include "parsing.h"
# include "tokenizer.h"

typedef struct s_exec
{
	char	**env_array;
	int		status;
	int		i;
	int		pipe_fd[2];
}	t_exec;

int		format_quotes(t_list *list_cmd, t_env *env);

char	*get_path(char *path, char *cmd);
int		exec_split_cmd(t_list *list_cmd, t_env *env);
int		switch_cmd_path(t_cmd *cmd, t_env *env);
int		is_in_builtins(char *cmd);
char	*get_cmd_local_path(char *cmd, t_env *env);
void	print_return_value(int return_code);
void	__wait(int i);
void	__close(void *content);
int		check_file(char *cmd, char *input);

/**
 * @brief				spawn a heredoc
 *
 * @param delimiter		a string representing the delimiter of the heredoc
 *
 * @return (int)		fd of a file containing the user's input, or -1 on error
 */
int		ft_heredoc(char *delimiter, t_cmd *cmd);
int		__open_fd_here(char *path, int mode);
void	ft_lstclear_till_nxt(t_list **lst, void (*del)(void *));
int		get_fd_heredoc(int in);
int		check_error(int heredoc_ret, int fd);
void	__heredoc_sig(int code);
int		fd_manager(int mode);

#endif
