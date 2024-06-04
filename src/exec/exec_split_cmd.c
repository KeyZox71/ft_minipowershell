/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_split_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:55:06 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/02 21:15:03 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd_path(char *cmd, t_env *env)
{
	int		i;
	char	*path;
	char	**path_list;

	path = NULL;
	path_list = get_path(env_get_value("PATH2", env));
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

int	exec_single_cmd(t_cmd *cmd, char **env, t_env *env_t)
{
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
	if (cmd->cmd[0] != '/')
		cmd->cmd = get_cmd_path(cmd->cmd, env_t);
	if (!(cmd->cmd))
		return (-1);
	
	int	fork_pid = fork();
	if (fork_pid == -1)
		return (-1);
	if (!fork_pid)
	{
		status = execve(cmd->cmd, cmd->argv, env);
		exit(-1);
	}
	else
		waitpid(fork_pid, NULL, 0);
	if (status == -1)
		return (-1);
	return (0);
}

int	exec_split_cmd(t_list *list_cmd, t_env *env)
{
	char	**env_array;
	int		status;
	t_cmd	*cmd;

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
	cmd = list_cmd->content;
	status = dup2(cmd->infile, STDIN_FILENO);
	if (status == -1)
		return (-1);
	status = dup2(STDOUT_FILENO, cmd->outfile);
	if (status == -1)
		return (-1);
	if (cmd->cmd[0] != '/')
		cmd->cmd = get_cmd_path(cmd->cmd, env);
	if (!(cmd->cmd))
		return (-1);
	int	fork_pid = fork();
	if (fork_pid == -1)
		return (-1);
	if (!fork_pid)
	{
		status = execve(cmd->cmd, cmd->argv, env_array);
		exit(-1);
	}
	else
		waitpid(fork_pid, NULL, 0);
	if (status == -1)
		return (-1);
	return (0);
}
