/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:25:18 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/14 10:23:48 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

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
			get_exit_code(128 + code);
			if (WCOREDUMP(return_code) && sigmsg[code])
				printf("minishell : %s %s\n", sigmsg[code], ERROR_COREDUMP);
			else if (sigmsg[code])
				printf("minishell : %s\n", sigmsg[code]);
		}
	}
	else
		get_exit_code(WEXITSTATUS(return_code));
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
	free(cmd);
	return (path);
}

int	switch_cmd_path(t_cmd *cmd, t_env *env)
{
	char	*path;

	if (is_in_builtins(cmd->cmd) || !cmd->cmd || !cmd->cmd[0])
		return (0);
	if (cmd->cmd[0] == '.' && cmd->cmd[1] == '/')
		cmd->cmd = get_cmd_local_path(cmd->cmd, env);
	else if (cmd->cmd[0] != '/')
	{
		path = env_get_value("PATH", env);
		cmd->cmd = get_path(path, cmd->cmd);
		free(path);
	}
	if (!(cmd->cmd))
		return (-1);
	return (0);
}

int	check_file(char *cmd, char *input)
{
	struct stat	entry;
	int			status;

	if (is_in_builtins(cmd))
		return (0);
	status = stat(cmd, &entry);
	if (status || !cmd || !*cmd)
	{
		get_exit_code(127);
		ft_printf_fd(2, "minishell : command not found: %s\n", input);
		return (1);
	}
	if (!S_ISDIR(entry.st_mode) && !access(cmd, X_OK))
		return (0);
	if (S_ISDIR(entry.st_mode))
	{
		get_exit_code(126);
		ft_printf_fd(2, "minishell : %s is a directory.\n", input);
	}
	else
	{
		get_exit_code(127);
		ft_printf_fd(2, "minishell : command not found: %s\n", input);
	}
	return (1);
}
