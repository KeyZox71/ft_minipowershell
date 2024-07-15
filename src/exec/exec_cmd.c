/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:03:31 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/15 21:04:44 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

void	exec_cmd(char *cmd, char **argv, char **env, t_env *env_t)
{
	int	i;

	i = is_in_builtins(cmd);
	if (i)
	{
		if (i == 5)
			ft_echo(argv + 1);
		if (i == 2)
			ft_cd(env_t, argv[1]);
		if (i == 6)
			ft_pwd();
		if (i == 4)
			ft_export(argv + 1, env_t);
		if (i == 3)
			ft_unset(argv[1], env_t);
		if (i == 7)
			ft_env(env_t);
		if (i == 1)
			ft_exit(argv, ft_arrlen(argv), env, env_t);
	}
	else
	{
		ft_envclear(&env_t, free);
		execve(cmd, argv, env);
	}
}

void	__fork_single_cmd(t_cmd *cmd, char **env, t_env *env_t, t_exec exec)
{
	exec.status = dup2(cmd->infile, STDIN_FILENO);
	if (cmd->infile != STDIN_FILENO)
		close(cmd->infile);
	if (exec.status == -1)
		exit(-1);
	exec.status = dup2(cmd->outfile, STDOUT_FILENO);
	if (cmd->outfile != STDOUT_FILENO)
		close(cmd->outfile);
	if (exec.pipe_fd[0] != -1)
		close(exec.pipe_fd[0]);
	if (exec.pipe_fd[0] != -1)
		close(exec.pipe_fd[1]);
	if (exec.status != -1)
		exec_cmd(cmd->cmd, cmd->argv, env, env_t);
	exit(-1);
}
