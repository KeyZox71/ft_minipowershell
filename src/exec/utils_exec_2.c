/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:53:01 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/09 22:57:38 by adjoly           ###   ########.fr       */
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
