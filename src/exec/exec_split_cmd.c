/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_split_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:55:06 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/18 20:29:40 by mmoussou         ###   ########.fr       */
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

int	exec_single_cmd(t_cmd *cmd, char **env, t_env *env_t)
{
	int	fork_pid;
	int	status;

	fork_pid = fork();
	if (fork_pid == -1)
		return (-1);
	if (!fork_pid)
	{
		status = dup2(cmd->infile, STDIN_FILENO);
		if (status == -1)
			return (-1);
		if (cmd->outfile != STDOUT_FILENO)
			status = dup2(STDOUT_FILENO, cmd->outfile);
		else
			status = dup2(STDOUT_FILENO, STDIN_FILENO);
		if (status == -1)
			return (-1);
		status = switch_cmd_path(cmd, env_t);
		if (status == -1)
			return (-1);
		execve(cmd->cmd, cmd->argv, env);
		exit(-1);
	}
	return (0);
}

int	exec_last_cmd(t_cmd *cmd, char **env, t_env *env_t)
{
	int	fork_pid;
	int	status;

	fork_pid = fork();
	if (fork_pid == -1)
		return (-1);
	if (!fork_pid)
	{
		status = dup2(cmd->infile, STDIN_FILENO);
		if (status == -1)
			return (-1);
		status = dup2(STDOUT_FILENO, cmd->outfile);
		if (status == -1)
			return (-1);
		status = switch_cmd_path(cmd, env_t);
		if (status == -1)
			return (-1);
		status = execve(cmd->cmd, cmd->argv, env);
		exit(-1);
	}
	return (0);
}

int	exec_split_cmd(t_list *list_cmd, t_env *env)
{
	char	**env_array;
	int		status;
	int		return_code;

	env_array = env_get(env);
	if (!env_array)
		return (-1);
	while (list_cmd->next)
	{
		status = exec_single_cmd(list_cmd->content, env_array, env);
		if (status == -1)
		{
			ft_free("a", &env_array);
			return (-1);
		}
		list_cmd = list_cmd->next;
	}
	status = exec_last_cmd(list_cmd->content, env_array, env);
	ft_free("a", &env_array);
	if (status == -1)
		return (-1);
	waitpid(-1, &return_code, 0);
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
