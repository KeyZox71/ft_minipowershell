/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/18 20:50:05 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"

# define HEREDOC_FD -2

typedef struct s_cmd
{
	char	*cmd;
	char	**argv;
	int		infile;
	int		outfile;
}	t_cmd;

t_cmd	*split_cmd(char *cmd_av);
t_list	*split_pipe(char *readline);

#endif
