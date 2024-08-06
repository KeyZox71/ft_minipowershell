/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:38:11 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/05 16:22:38 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ign(int signal)
{
	(void) signal;
}

void	__sig2(int status)
{
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
	{
		get_exit_code(131);
		if (WCOREDUMP(status))
			ft_putendl_fd("Quit (core dumped)", 2);
		else
			ft_putendl_fd("Quit", 2);
	}
}

void	__sig(void)
{
	signal(SIGQUIT, ign);
	signal(SIGINT, ign);
}
