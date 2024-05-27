/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:25:42 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/27 19:01:17 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "prompt.h"
#include "env.h"

char	*get_prompt(t_env env)
{
	char	*prompt;

	prompt = env_get_value("USER", &env);//getenv("USER");
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
	prompt = ft_strjoin_free(prompt, get_pwd(env));
	if (!prompt)
		return (NULL);
	prompt = ft_strjoin_free_s1(prompt, "$ ");
	if (!prompt)
		return (NULL);
	return (prompt);
}
