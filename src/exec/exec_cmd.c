/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:03:31 by mmoussou          #+#    #+#             */
/*   Updated: 2024/08/13 18:39:22 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "error_msg.h"

void	exec_cmd(t_cmd *cmd, char **env, t_env *env_t)
{
	int	i;

	i = is_in_builtins(cmd->cmd);
	if (i)
	{
		if (i == 5)
			ft_echo(cmd->argv + 1);
		if (i == 2)
			ft_cd(env_t, (cmd->argv)[1]);
		if (i == 6)
			ft_pwd();
		if (i == 4)
			ft_export(cmd->argv + 1, env_t, cmd->outfile);
		if (i == 3)
			ft_unset(&(cmd->argv)[1], env_t);
		if (i == 7)
			ft_env(env_t);
		if (i == 1)
			ft_exit(cmd->argv, ft_arrlen(cmd->argv), env, env_t);
	}
	else
	{
		ft_envclear(&env_t, free);
		execve(cmd->cmd, cmd->argv, env);
	}
}

void	__fork_single_cmd(t_cmd *cmd, char **env, t_env *env_t, t_exec exec)
{
	int	i;

	exec.status = dup2(cmd->infile, STDIN_FILENO);
	if (cmd->infile != STDIN_FILENO)
		close(cmd->infile);
	exec.status = dup2(cmd->outfile, STDOUT_FILENO);
	if (cmd->outfile != STDOUT_FILENO)
		close(cmd->outfile);
	if (exec.pipe_fd[0] != -1)
		close(exec.pipe_fd[0]);
	if (exec.pipe_fd[0] != -1)
		close(exec.pipe_fd[1]);
	if (exec.status != -1)
	{
		if (is_in_builtins(cmd->cmd) == 1)
			close(STDOUT_FILENO);
		i = 2;
		while (i++ < 1023)
			close(i);
		get_env_arr(env);
		if (is_in_builtins(cmd->cmd))
			signal(SIGPIPE, sig_p);
		exec_cmd(cmd, env, env_t);
	}
}

int	exec_single_cmd_execution(t_cmd *cmd, char **env, t_env *env_t, t_exec exec)
{
	int		fork_pid;

	if (is_in_builtins(cmd->cmd) > 0 && is_in_builtins(cmd->cmd) < 5)
		exec_cmd(cmd, env, env_t);
	if (is_in_builtins(cmd->cmd) > 0 && is_in_builtins(cmd->cmd) < 5)
		return (0);
	fork_pid = fork();
	if (!fork_pid)
	{
		__fork_single_cmd(cmd, env, env_t, exec);
		free_exit(env_t, env);
		exit(get_exit_code(-1));
	}
	return (fork_pid);
}
