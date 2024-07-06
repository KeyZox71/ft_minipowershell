/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_split_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:55:06 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/06 14:23:32 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"
#include "error_msg.h"

int	is_in_builtins(char *cmd)
{
	int					i;
	static const char	*builtins[] = {"exit", "cd", "unset", "export", "echo",
		"pwd", "env", NULL};

	i = 0;
	while (builtins[i])
	{
		if (!ft_strcmp(cmd, builtins[i]))
			return (i + 1);
		i++;
	}
	return (0);
}

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
			exit(ft_atoi(argv[1]));
		if (i > 4)
			exit(0);
	}
	else
		execve(cmd, argv, env);
}

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
	if (is_in_builtins(cmd->cmd))
		return (0);
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
	int		fork_pid;
	int		status;
	char	*input;

	input = ft_strdup(cmd->cmd);
	status = switch_cmd_path(cmd, env_t);
	if (status == -1 || !input || (access(cmd->cmd, X_OK) && !is_in_builtins(cmd->cmd)))
	{
		printf("minishell : command not found: %s\n", input);
		return (-1);
	}
	if (is_in_builtins(cmd->cmd) && is_in_builtins(cmd->cmd) < 5)
	{
		exec_cmd(cmd->cmd, cmd->argv, env, env_t);
		return (0);
	}
	fork_pid = fork();
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
		if (pipe_fd[0] != -1)
			close(pipe_fd[0]);
		if (pipe_fd[0] != -1)
			close(pipe_fd[1]);
		if (status != -1)
			exec_cmd(cmd->cmd, cmd->argv, env, env_t);
		exit(-1);
	}
	return (fork_pid);
}

void	print_return_value(int return_code)
{
	int					code;
	static const char	*sigmsg[] = {0, "Hangup", 0, "Quit", "Illegal \
		instruction", "Trace/breakpoint trap", "Aborted", "Bus error",
		"Floating point exception", "Killed", "User defined signal 1",
		"Segmentation fault", "User defined signal 2", 0,
		"Alarm clock", "Terminated", "Stack fault", 0, 0, "Stopped", "Stopped",
		"Stopped", "Stopped", 0, "CPU time limit exceeded",
		"File size limit exceeded", "Virtual time expired",
		"Profiling timer expired", "I/O possible", "Power failure",
		"Bad system call"};

	if (!WIFEXITED(return_code))
	{
		if (WIFSIGNALED(return_code))
		{
			code = WTERMSIG(return_code);
			if (!sigmsg[code])
				return ;
			if (WCOREDUMP(return_code))
				printf("minishell : %s %s\n", sigmsg[code], ERROR_COREDUMP);
			else
				printf("minishell : %s\n", sigmsg[code]);
		}
	}
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
	i = 1;
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
		if (status != -1)
			i++;
		list_cmd = list_cmd->next;
	}
	status = exec_single_cmd(list_cmd->content, env_array, env, pipe_fd);
	if (((t_cmd *)(list_cmd->content))->outfile != STDOUT_FILENO)
		close(((t_cmd *)(list_cmd->content))->outfile);
	if (((t_cmd *)(list_cmd->content))->infile != STDIN_FILENO)
		close(((t_cmd *)(list_cmd->content))->infile);
	ft_free("a", &env_array);
	if (status == -1)
		i--;
	if (i < 1)
		return (0);
	if (status != 0)
		waitpid(status, &return_code, 0);
	while (i - 1)
	{
		waitpid(-1, NULL, 0);
		i--;
	}
	print_return_value(return_code);
	return (0);
}
