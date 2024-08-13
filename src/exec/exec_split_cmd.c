/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_split_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:55:06 by mmoussou          #+#    #+#             */
/*   Updated: 2024/08/13 16:54:52 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "error_msg.h"
#include "execution.h"

void	__sig(int status);
void	__sig2(int status);

int	exec_fork_cmd(t_cmd *cmd, char **env, t_env *env_t, int pipe_fd[2])
{
	t_exec	exec;
	int		fork_pid;
	char	*input;

	if (!cmd->cmd)
		return (close_cmd(cmd));
	ft_arrcpy(exec.pipe_fd, pipe_fd, 2);
	input = ft_strdup(cmd->cmd);
	exec.status = switch_cmd_path(cmd, env_t);
	if (exec.status == -1 || !input || check_file(cmd->cmd, input))
	{
		if (exec.status == -1)
			printf("minishell : command not found: %s\n", input);
		free(input);
		return (get_exit_code(127));
	}
	free(input);
	fork_pid = fork();
	if (!fork_pid)
	{
		__fork_single_cmd(cmd, env, env_t, exec);
		free_exit(env_t, env);
		exit(get_exit_code(-1));
	}
	return (fork_pid);
}

int	exec_single_cmd(t_cmd *cmd, char **env, t_env *env_t, int pipe_fd[2])
{
	t_exec	exec;
	char	*input;

	if (!cmd->cmd)
	{
		free_cmd(cmd);
		rl_clear_history();
		get_exit_code(0);
		return (0);
	}
	input = ft_strdup(cmd->cmd);
	exec.pipe_fd[0] = pipe_fd[0];
	exec.pipe_fd[1] = pipe_fd[1];
	exec.status = switch_cmd_path(cmd, env_t);
	if (exec.status == -1 || !input || check_file(cmd->cmd, input))
	{
		if (exec.status == -1)
			printf("minishell : command not found: %s\n", input);
		free(input);
		return (get_exit_code(127));
	}
	free(input);
	exec.status = exec_single_cmd_execution(cmd, env, env_t, exec);
	return (exec.status);
}

t_exec	exec_pipe_unforked(t_exec exec, t_list *list_cmd, t_env *env)
{
	exec.status = exec_single_cmd(list_cmd->content, exec.env_array, \
			env, exec.pipe_fd);
	__sig(exec.status);
	if (((t_cmd *)(list_cmd->content))->outfile != STDOUT_FILENO)
		close(((t_cmd *)(list_cmd->content))->outfile);
	if (((t_cmd *)(list_cmd->content))->infile != STDIN_FILENO)
		close(((t_cmd *)(list_cmd->content))->infile);
	return (exec);
}

t_exec	exec_pipe(t_exec exec, t_list *list_cmd, t_env *env)
{
	__sig(exec.status);
	if (!list_cmd->next)
		return (exec_pipe_unforked(exec, list_cmd, env));
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
		exec.status = exec_fork_cmd(list_cmd->content, exec.env_array, \
			env, exec.pipe_fd);
		__close(list_cmd->content, -1, -1);
		if (exec.status != -1)
			exec.i++;
		list_cmd = list_cmd->next;
	}
	exec.status = exec_fork_cmd(list_cmd->content, exec.env_array, \
		env, exec.pipe_fd);
	__sig2(exec.status);
	__close(list_cmd->content, exec.pipe_fd[0], exec.pipe_fd[1]);
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
