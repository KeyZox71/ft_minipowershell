/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/07 14:07:10 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "libft.h"

typedef struct s_cmd
{
	char	*cmd;
	char	**argv;
}	t_cmd;

typedef struct s_parsing
{
	
}	t_parsing;

t_cmd	*split_cmd(char *cmd_av);
t_list	*split_pipe(char *readline);

#endif
