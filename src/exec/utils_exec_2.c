/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:53:01 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/15 15:23:00 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	__wait(int i)
{
	while (i - 1)
	{
		waitpid(-1, NULL, 0);
		i--;
	}
}

void	__close(void *content)
{
	if (((t_cmd *)(content))->outfile != STDOUT_FILENO)
		close(((t_cmd *)(content))->outfile);
	if (((t_cmd *)(content))->infile != STDIN_FILENO)
		close(((t_cmd *)(content))->infile);
}

int	send_error_exec(char *input)
{
	printf("minishell : command not found: %s\n", input);
	free(input);
	return (-1);
}

void	__sig(int status)
{
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
	{
		get_exit_code(131);
		if (WCOREDUMP(status))
			ft_putendl_fd("Quit (core dumped)", 2);
		else
			ft_putendl_fd("Quit", 2);
	}	
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}
