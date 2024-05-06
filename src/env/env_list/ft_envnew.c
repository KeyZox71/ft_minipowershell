/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:02:40 by mmoussou          #+#    #+#             */
/*   Updated: 2024/05/03 15:47:23 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_envnew(char *name, char *content)
{
	t_env	*r;

	r = malloc(sizeof(t_env));
	if (!r)
		return (NULL);
	r->name = name;
	r->content = content;
	r->next = NULL;
	return (r);
}
