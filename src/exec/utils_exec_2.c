/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 22:53:01 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/12 16:16:43 by mmoussou         ###   ########.fr       */
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

void	__close(void *content, int fd1, int fd2)
{
	if (((t_cmd *)(content))->outfile != STDOUT_FILENO)
		close(((t_cmd *)(content))->outfile);
	if (((t_cmd *)(content))->infile != STDIN_FILENO)
		close(((t_cmd *)(content))->infile);
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
}

int	send_error_exec(char *input)
{
	printf("minishell : command not found: %s\n", input);
	free(input);
	return (-1);
}

void	ft_arrcpy(int *dst, int *src, int n)
{
	while (n--)
		dst[n] = src[n];
}
