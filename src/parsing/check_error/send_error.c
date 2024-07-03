/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:09:49 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/03 16:15:52 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_program_name(char	*argv_one)
{
	static char	prog_name[255];

	if (argv_one)
		ft_strlcpy(prog_name, argv_one, ft_strlen(argv_one) + 1);
	return (prog_name);
}

bool	send_error_parsing(char *msg)
{
	ft_putstr_fd(get_program_name(NULL), STDERR_FILENO);
	ft_putstr_fd(": Error: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	return (true);
}
