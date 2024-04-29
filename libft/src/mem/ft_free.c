/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:27:31 by mmoussou          #+#    #+#             */
/*   Updated: 2024/01/18 01:05:44 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}

void	free_stack(t_stack **stack)
{
	if (*stack && (*stack)->next)
		free_stack(&(*stack)->next);
	free(*stack);
	*stack = NULL;
}

void	free_list(t_list **lst)
{
	if (*lst && (*lst)->next)
		free_list(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}

void	free_tab(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	ft_free(const char *str, ...)
{
	va_list	args;
	size_t	i;

	if (!str)
		return ;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == 'c')
			free_str(va_arg(args, char **));
		if (str[i] == 's')
			free_stack(va_arg(args, t_stack **));
		if (str[i] == 'l')
			free_list(va_arg(args, t_list **));
		if (str[i] == 'a')
			free_tab(va_arg(args, char ***));
		i++;
	}
}
