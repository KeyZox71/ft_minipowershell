/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_split_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:55:06 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/14 14:44:18 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "error_msg.h"
#include "execution.h"

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
			ft_exit(argv, ft_arrlen(argv));
	}
	else
		execve(cmd, argv, env);
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

int	exec_single_cmd(t_cmd *cmd, char **env, t_env *env_t, int pipe_fd[2])
{
	t_exec	exec;
	int		fork_pid;
	char	*input;

	input = ft_strdup(cmd->cmd);
	exec.pipe_fd[0] = pipe_fd[0];
	exec.pipe_fd[1] = pipe_fd[1];
	exec.status = switch_cmd_path(cmd, env_t);
	if (exec.status == -1 || !input || (access(cmd->cmd, X_OK) \
		&& !is_in_builtins(cmd->cmd)))
	{
		printf("minishell : command not found: %s$\n", input);
		free(input);
		return (-1);
	}
	free(input);
	if (is_in_builtins(cmd->cmd) > 0)
	{
		exec_cmd(cmd->cmd, cmd->argv, env, env_t);
		return (0);
	}
	fork_pid = fork();
	if (!fork_pid)
		__fork_single_cmd(cmd, env, env_t, exec);
	return (fork_pid);
}

t_exec	exec_pipe(t_exec exec, t_list *list_cmd, t_env *env)
{
	while (list_cmd->next)
	{
		exec.status = pipe(exec.pipe_fd);
		if (exec.status)
			return ((t_exec){exec.env_array, -1, exec.i, \
				{exec.pipe_fd[0], exec.pipe_fd[1]}});
		if (((t_cmd *)(list_cmd->content))->outfile == STDOUT_FILENO)
			((t_cmd *)(list_cmd->content))->outfile = exec.pipe_fd[1];
		if (((t_cmd *)(list_cmd->next->content))->infile == STDIN_FILENO)
			((t_cmd *)(list_cmd->next->content))->infile = exec.pipe_fd[0];
		exec.status = exec_single_cmd(list_cmd->content, exec.env_array, \
			env, exec.pipe_fd);
		__close(list_cmd->content);
		if (exec.status != -1)
			exec.i++;
		list_cmd = list_cmd->next;
	}
	exec.status = exec_single_cmd(list_cmd->content, exec.env_array, \
		env, exec.pipe_fd);
	if (((t_cmd *)(list_cmd->content))->outfile != STDOUT_FILENO)
		close(((t_cmd *)(list_cmd->content))->outfile);
	if (((t_cmd *)(list_cmd->content))->infile != STDIN_FILENO)
		close(((t_cmd *)(list_cmd->content))->infile);
	return (exec);
}

int	exec_split_cmd(t_list *list_cmd, t_env *env)
{
	t_exec	exec;
	int		return_code;

	exec.env_array = env_get(env);
	if (!exec.env_array)
		return (-1);
	return_code = 0;
	exec.pipe_fd[0] = -1;
	exec.pipe_fd[1] = -1;
	exec.i = 1;
	exec = exec_pipe(exec, list_cmd, env);
	if (exec.env_array)
		ft_free("a", &exec.env_array);
	if (exec.status == -1)
		exec.i--;
	if (exec.i < 1)
		return (0);
	if (exec.status != 0)
		waitpid(exec.status, &return_code, 0);
	if (!return_code)
		return_code = 0;
	__wait(exec.i);
	print_return_value(return_code);
	return (0);
}
