/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:20:22 by mmoussou          #+#    #+#             */
/*   Updated: 2024/08/13 18:39:43 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "env.h"
# include "libft.h"
# include "parsing.h"

typedef struct s_exec
{
	char	**env_array;
	int		status;
	int		i;
	int		pipe_fd[2];
}	t_exec;

void	format_quotes(char **content);

int		exec_single_cmd_execution(t_cmd *cmd, char **env,
			t_env *env_t, t_exec exec);
char	*get_path(char *path, char *cmd);
int		exec_split_cmd(t_list *list_cmd, t_env *env);
int		switch_cmd_path(t_cmd *cmd, t_env *env);
int		is_in_builtins(char *cmd);
char	*get_cmd_local_path(char *cmd, t_env *env);
void	print_return_value(int return_code);
void	__wait(int i);
void	__close(void *content, int fd1, int fd2);
int		check_file(char *cmd, char *input);
void	free_exec(t_env *env, char **env_array);
void	ft_arrcpy(int *dst, int *src, int n);

int		close_cmd(t_cmd *cmd);

char	**get_env_arr(char **env);
void	sig_p(int code);

void	exec_cmd(t_cmd *cmd, char **env, t_env *env_t);
void	__fork_single_cmd(t_cmd *cmd, char **env, t_env *env_t, t_exec exec);

/**
 * @brief				spawn a heredoc
 *
 * @param delimiter		a string representing the delimiter of the heredoc
 *
 * @return (int)		fd of a file containing the user's input, or -1 on error
 */
int		ft_heredoc(char *delimiter, t_list *list);
int		__open_fd_here(char *path, int mode);
void	ft_lstclear_till_nxt(t_list **lst, void (*del)(void *));
int		get_fd_heredoc(int in);
int		check_error(int heredoc_ret, int fd);
void	__heredoc_sig(int code);
int		fd_manager(int mode);

#endif
