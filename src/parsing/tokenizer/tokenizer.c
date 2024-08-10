/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:13:50 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/10 17:46:54 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minishell.h"
#include <stdio.h>

t_list	**get_list2(t_list **list);

void	*clear_all(t_list *cmd, t_list *piped)
{
	ft_lstclear(&cmd, free_cmd);
	ft_lstclear(&piped, free);
	return (NULL);
}

t_list	*tokenizer(char *readline, t_env *env)
{
	t_list	*cmd;
	t_list	*piped;
	t_list	*tmp;

	(void)(env);
	piped = __split_pipe(readline);
	free(readline);
	cmd = NULL;
	tmp = piped;
	get_list(&piped);
	while (tmp)
	{
		ft_lstadd_back(&cmd,
			ft_lstnew(__to_cmd(split_argv(env_var_replace(tmp->content,
							env)))));
		if (((t_cmd *)ft_lstlast(cmd)->content)->infile == -2)
			return (clear_all(cmd, piped));
		if (!cmd->next)
			get_list2(&cmd);
		if (!ft_lstlast(cmd)->content)
			return (clear_all(cmd, piped));
		tmp = tmp->next;
	}
	ft_lstclear(&piped, free);
	return (cmd);
}
