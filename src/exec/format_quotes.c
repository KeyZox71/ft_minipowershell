/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:50:52 by mmoussou          #+#    #+#             */
/*   Updated: 2024/07/15 18:17:50 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	__get_size_in_quote(char *cmd)
{
	char	*tmp;

	tmp = search_for_next_quote(cmd + 1, __is_quote(*cmd));
	return (tmp - cmd);
}

char	*format_quotes_string(char *cmd)
{
	size_t	inquote;
	char	*tmp;
	char	*ret;

	if (!cmd)
		return (NULL);
	tmp = cmd;
	ret = ft_calloc(ft_strlen(cmd) + 1, sizeof(char));
	while (*tmp)
	{
		if (*tmp == DOUBLE || *tmp == SINGLE)
		{
			inquote = __get_size_in_quote(tmp);
			ft_strlcat(ret, tmp + 1, ft_strlen(ret) + inquote);
			tmp += inquote;
		}
		else if (*tmp == -1)
		{
			ft_strlcat(ret, "\'", ft_strlen(ret) + 2);
			tmp++;
		}
		else if (*tmp == -1)
		{
			ft_strlcat(ret, "\"", ft_strlen(ret) + 2);
			tmp++;
		}
		else
		{
			ft_strlcat(ret, tmp, ft_strlen(ret) + 2);
			tmp++;
		}
	}
	free(cmd);
	return (ret);
}

//char	*format_quotes_string(char *cmd)
//{
//	if (!cmd)
//		return (NULL);
//	if (*cmd == DOUBLE || *cmd == SINGLE)
//		ft_strlcpy(cmd, cmd + 1, ft_strlen(cmd) - 1);
//	return (cmd);
//}

int	format_quotes_cmd(t_cmd *cmd)
{
	uint	i;

	if (!cmd)
		return (-1);
	cmd->cmd = format_quotes_string(cmd->cmd);
	i = 0;
	while (cmd->argv[i])
	{
		cmd->argv[i] = format_quotes_string(cmd->argv[i]);
		i++;
	}
	return (0);
}

int	format_quotes(t_list *list_cmd)
{
	if (!list_cmd)
		return (0);
	while (list_cmd)
	{
		if (format_quotes_cmd(list_cmd->content))
			return (-1);
		list_cmd = list_cmd->next;
	}
	return (0);
}
