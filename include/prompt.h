/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:48:05 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/19 14:20:45 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

/**
 * @brief				return the short hostname from /etc/hostname
 *						or return nixos if file doesn't exist or is empty
 *
 * @return (char *)		The short hostname
 */
char	*get_hostname(void);

/**
 * @brief				return the pwd (from the env), and if in home put a ~ 
 *						replacing the home directory
 *
 * @return (char *)		the pwd
 */
char	*get_pwd(void);

/**
 * @brief				return the full prompt
 *
 * @prompt (char *)		the prompt
 */
char	*get_prompt(void);

#endif
