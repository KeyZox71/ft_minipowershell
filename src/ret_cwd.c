/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_cwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:41:43 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/25 17:04:37 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "libft.h"
#include <unistd.h>

char	*ret_cwd(void)
{
	static char	buf[PATH_MAX_LEN];

	ft_bzero(buf, PATH_MAX_LEN);
	return (getcwd(buf, PATH_MAX_LEN));
}
