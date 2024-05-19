/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/19 13:45:01 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "tokenizer.h"

typedef struct s_cmd
{
	char	*cmd;
	char	**argv;
	int		infile;
	int		outfile;
}	t_cmd;

/**
 * @brief				Take the argv of a command a split the argv and the command it self
 *
 * @param				The full argv of the command
 *
 * @return (t_cmd *)	cmd and argv splited into a struct
 */
t_cmd	*split_cmd(char *cmd_av);

/*
 *	@deprecated
 */
t_list	*split_pipe(char *readline);

#endif
