/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_split_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:55:06 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/23 03:47:39 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd_local_path(char *cmd, t_env *env)
{
	char	*path;

	path = env_get_value("PWD", env);
	if (!path)
		return (NULL);
	path = ft_strjoin_free_s1(path, "/");
	if (!path)
		return (NULL);
	path = ft_strjoin_free_s1(path, cmd);
	return (path);
}

int	switch_cmd_path(t_cmd *cmd, t_env *env)
{
	if (cmd->cmd[0] == '.' && cmd->cmd[1] == '/')
		cmd->cmd = get_cmd_local_path(cmd->cmd, env);
	else if (cmd->cmd[0] != '/')
		cmd->cmd = get_path(env_get_value("PATH", env), cmd->cmd);
	if (!(cmd->cmd))
		return (-1);
	return (0);
}

int	exec_single_cmd(t_cmd *cmd, char **env, t_env *env_t, int pipe_fd[2])
{
	int	fork_pid;
	int	status;

	status = switch_cmd_path(cmd, env_t);
	if (status == -1 || access(cmd->cmd, X_OK))
		return (-1);
	fork_pid = fork();
	if (fork_pid == -1)
		return (-1);
	if (!fork_pid)
	{
		status = dup2(cmd->infile, STDIN_FILENO);
		if (cmd->infile != STDIN_FILENO)
			close(cmd->infile);
		if (status == -1)
			exit(-1);
		status = dup2(cmd->outfile, STDOUT_FILENO);
		if (cmd->outfile != STDOUT_FILENO)
			close(cmd->outfile);
		if (status == -1)
			exit(-1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(cmd->cmd, cmd->argv, env);
		exit(-1);
	}
	return (0);
}

int	exec_split_cmd(t_list *list_cmd, t_env *env)
{
	char	**env_array;
	int		status;
	int		return_code;
	int		i;
	int		pipe_fd[2];

	env_array = env_get(env);
	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	if (!env_array)
		return (-1);
	i = ft_lstsize(list_cmd);
	while (list_cmd->next)
	{
		status = pipe(pipe_fd);
		if (status)
			return (-1);
		if (((t_cmd *)(list_cmd->content))->outfile == STDOUT_FILENO)
			((t_cmd *)(list_cmd->content))->outfile = pipe_fd[1];
		if (((t_cmd *)(list_cmd->next->content))->infile == STDIN_FILENO)
			((t_cmd *)(list_cmd->next->content))->infile = pipe_fd[0];
		status = exec_single_cmd(list_cmd->content, env_array, env, pipe_fd);
		if (((t_cmd *)(list_cmd->content))->outfile != STDOUT_FILENO)
			close(((t_cmd *)(list_cmd->content))->outfile);
		if (((t_cmd *)(list_cmd->content))->infile != STDIN_FILENO)
			close(((t_cmd *)(list_cmd->content))->infile);
		if (status == -1)
		{
			ft_free("a", &env_array);
			return (-1);
		}
		list_cmd = list_cmd->next;
	}
	status = exec_single_cmd(list_cmd->content, env_array, env, pipe_fd);
	if (((t_cmd *)(list_cmd->content))->outfile != STDOUT_FILENO)
		close(((t_cmd *)(list_cmd->content))->outfile);
	if (((t_cmd *)(list_cmd->content))->infile != STDIN_FILENO)
		close(((t_cmd *)(list_cmd->content))->infile);
	ft_free("a", &env_array);
	if (status == -1)
		return (-1);
	while (i)
	{
		waitpid(-1, &return_code, 0);
		i--;
	}
	if (WIFEXITED(return_code))
		printf("minishell: %d\n", WEXITSTATUS(return_code));
	else
	{
		if (WIFSIGNALED(return_code))
		{
			if (WCOREDUMP(return_code))
				printf("minishell: %d\n", WTERMSIG(return_code));
			else
				printf("minishell: %d\n", WTERMSIG(return_code));
		}
	}
	return (0);
}
