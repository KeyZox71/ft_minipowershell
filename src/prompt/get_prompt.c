/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:25:42 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/02 15:50:14 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*get_prompt(void)
{
	char	*prompt;

	prompt = getenv("USER");
	prompt = ft_strjoin(prompt, "@");
	prompt = ft_strjoin_free(prompt, get_hostname());
	prompt = ft_strjoin_free_s1(prompt, ":");
	prompt = ft_strjoin_free(prompt, get_pwd());
	prompt = ft_strjoin_free_s1(prompt, "$ ");
	return (prompt);
}
