/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:18:04 by adjoly            #+#    #+#             */
/*   Updated: 2024/05/24 15:01:05 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include "libft.h"
#include "minishell.h"
#include "parsing.h"
#include "prompt.h"

/*void	print_cmd(t_cmd cmd)
{
	ft_putendl_fd(cmd.cmd, 1);	
	while (*(cmd.argv))
	{
		ft_putendl_fd(*(cmd.argv), 1);
		(cmd.argv)++;
	}
}*/

void	print_pipe(t_list *pipe)
{
	t_list	*tmp;

	tmp = pipe;
	while (tmp)
	{
		ft_putendl_fd(tmp->content, STDOUT_FILENO);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*test;
	char	*prompt;
	char	**lll;
	t_list	*piped;
	//t_token	*token;

	(void)ac;
	(void)av;
	(void)env;
	while (1)
	{
		prompt = get_prompt();
		test = readline(prompt);
		free(prompt);
		add_history(test);
		lll = ft_split(test, ' ');
		if (!*lll)
			continue;
		if (is_str(test, "exit"))
			break;
		piped = __split_pipe(test);
		print_redir(__to_redir(piped->content));
		//free(token);
		free(test);
		ft_lstclear(&piped, &free);
	}
	ft_free("a", &lll);
	return (0);
}

/*int	main()
{
	char	*ll = "asdf\"xf\"asfffd";
	t_quote	d;

	d = is_inquote(ll, 6);
	ft_printf("%c\n", *(ll+6));
	print_quote_type(d);
}*/
