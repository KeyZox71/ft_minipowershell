/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_split_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:55:06 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/05 01:08:00 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd_global_path(char *cmd, t_env *env)
{
	int		i;
	char	*path;
	char	**path_list;

	path = NULL;
	path_list = get_path(env_get_value("PATH", env));
	if (!path_list)
		return (NULL);
	i = 0;
	while (path_list[i])
	{
		if (!ft_strcmp(ft_strrchr(path_list[i], '/') + 1, cmd))
		{
			path = ft_strdup(path_list[i]);
			return (path);
		}
		i++;
	}
	free(cmd);
	return (path);
}

char	*get_cmd_local_path(char *cmd, t_env *env)
{
	(void) cmd;
	(void) env;
	// TODO : get pwd, append cmd, done.
	return (NULL);
}

int	switch_cmd_path(t_cmd *cmd, t_env *env)
{
	if (cmd->cmd[0] != '/')
		cmd->cmd = get_cmd_global_path(cmd->cmd, env);
	else if (cmd->cmd[0] == '.' && cmd->cmd[1] == '/')
		cmd->cmd = get_cmd_local_path(cmd->cmd, env);
	if (!(cmd->cmd))
		return (-1);
	return (0);
}

int	exec_single_cmd(t_cmd *cmd, char **env, t_env *env_t)
{
	int	fork_pid;
	int	status;

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
	if (!status)
		return (-1);
	fork_pid = fork();
	if (fork_pid == -1)
		return (-1);
	if (!fork_pid)
		status = execve(cmd->cmd, cmd->argv, env);
	if (!fork_pid)
		exit(-1);
	else
		waitpid(fork_pid, NULL, 0);
	return (0);
}

int	exec_last_cmd(t_cmd *cmd, char **env, t_env *env_t)
{
	int	fork_pid;
	int	status;

	status = dup2(cmd->infile, STDIN_FILENO);
	if (status == -1)
		return (-1);
	status = dup2(STDOUT_FILENO, cmd->outfile);
	if (status == -1)
		return (-1);
	status = switch_cmd_path(cmd, env_t);
	if (!status)
		return (-1);
	fork_pid = fork();
	if (fork_pid == -1)
		return (-1);
	if (!fork_pid)
	{
		status = execve(cmd->cmd, cmd->argv, env);
		exit(-1);
	}
	else
		waitpid(fork_pid, NULL, 0);
	return (0);
}

int	exec_split_cmd(t_list *list_cmd, t_env *env)
{
	char	**env_array;
	int		status;

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
	return (0);
}
