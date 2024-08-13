/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:13:50 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/13 16:33:04 by adjoly           ###   ########.fr       */
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
	t_cmd	*ret;

	piped = __split_pipe(readline);
	free(readline);
	cmd = NULL;
	tmp = piped;
	get_list(&piped);
	while (tmp)
	{
		ret = __to_cmd(split_argv(env_var_replace(tmp->content, env)));
		ft_lstadd_back(&cmd, ft_lstnew(ret));
		if (!ret || ((t_cmd *)ret)->infile == -2 || !cmd)
			return (clear_all(cmd, piped));
		if (!cmd->next)
			get_list2(&cmd);
		tmp = tmp->next;
	}
	if (check_redir(cmd))
		return (clear_all(cmd, piped));
	ft_lstclear(&piped, free);
	return (cmd);
}
