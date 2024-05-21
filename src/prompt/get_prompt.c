/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:25:42 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/21 21:02:18 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prompt.h"

char	*get_prompt(void)
{
	char	*prompt;

	prompt = getenv("USER");
	if (!prompt)
		prompt = ft_strdup("nixos");
	prompt = ft_strjoin(prompt, "@");
	if (!prompt)
		return (NULL);
	prompt = ft_strjoin_free(prompt, get_hostname());
	if (!prompt)
		return (NULL);
	prompt = ft_strjoin_free_s1(prompt, ":");
	if (!prompt)
		return (NULL);
	prompt = ft_strjoin_free(prompt, get_pwd());
	if (!prompt)
		return (NULL);
	prompt = ft_strjoin_free_s1(prompt, "$ ");
	if (!prompt)
		return (NULL);
	return (prompt);
}
