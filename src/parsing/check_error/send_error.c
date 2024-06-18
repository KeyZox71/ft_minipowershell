/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:09:49 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/04 15:39:24 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	send_error(char *msg, char **argv)
{
	ft_putstr_fd(argv[0], STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
}
