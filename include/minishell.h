/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:38:51 by mmoussou          #+#    #+#             */
/*   Updated: 2024/05/06 20:30:42 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

# include "parsing.h"
# include "execution.h"

char	set_env(char **env, const char *name, char *content);
char	*get_hostname(void);
char	*get_prompt(void);
char	*get_pwd(void);

#endif
