/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:59:11 by mmoussou          #+#    #+#             */
/*   Updated: 2023/11/13 19:39:13 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_list(char **result, int j)
{
	while (j)
	{
		free(result[j]);
		j--;
	}
	return (1);
}

static int	word_counter(const char *str, char ch)
{
	int	i;
	int	c;
	int	bool_c;

	i = 0;
	c = 0;
	bool_c = 1;
	while (str[i])
	{
		if (str[i] == ch)
		{
			bool_c = 1;
		}
		else if (str[i] != ch && bool_c)
		{
			c++;
			bool_c = 0;
		}
		i++;
	}
	return (c);
}

static int	per_word_fill(char **result, const char *str, char ch)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	while (str[i])
	{
		c = 0;
		while (str[i] != ch && str[i])
		{
			c++;
			i++;
		}
		if (c != 0)
		{
			result[j] = ft_calloc(sizeof(char), c + 1);
			if (result[j++] == NULL)
				return (free_list(result, j - 2));
		}
		if (str[i])
			i++;
	}
	result[j] = NULL;
	return (0);
}

static void	ft_split_resolver(char **result, const char *str, char ch)
{
	int	i;
	int	j;
	int	wi;
	int	bool_w;

	i = 0;
	j = 0;
	wi = 0;
	bool_w = 0;
	while (str[i])
	{
		if (str[i] == ch && bool_w)
		{
			bool_w = 0;
			wi = 0;
			j++;
		}
		else if (str[i] != ch)
		{
			bool_w = 1;
			result[j][wi] = str[i];
			wi++;
		}
		i++;
	}
}

char	**ft_split(const char *str, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * (word_counter(str, c) + 1));
	if (result == NULL)
		return (NULL);
	if (per_word_fill(result, str, c))
		return (NULL);
	ft_split_resolver(result, str, c);
	return (result);
}
