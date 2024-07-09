/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_to_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:24:15 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/09 18:05:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

t_env	**get_env(t_env **env)
{
	static t_env	**ret;

	if (env)
		ret = env;
	return (ret);
}

t_list	**get_list(t_list **list)
{
	static t_list	**ret;
	
	if (list)
		ret = list;
	return (ret);
}
