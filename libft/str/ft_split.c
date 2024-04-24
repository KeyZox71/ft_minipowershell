/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 09:14:19 by adjoly            #+#    #+#             */
/*   Updated: 2024/02/04 14:43:50 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_countword(char const *s, char sep)
{
	int	i;
	int	w_count;

	i = 0;
	w_count = 0;
	while (s[i])
	{
		if (s[i] != sep && (i == 0 || s[i - 1] == sep))
			w_count++;
		i++;
	}
	return (w_count);
}

static int	ft_countletter(char const *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] != sep && s[i] != '\0')
		i++;
	return (i);
}

static void	*ft_freearr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split_to_result(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			tab[j] = ft_calloc(ft_countletter(&s[i], c) + 1, sizeof(char));
			if (!tab[j])
				return (ft_freearr(tab));
			while (s[i] && s[i] != c)
				tab[j][k++] = s [i++];
			tab[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = ft_calloc(ft_countword(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	result = ft_split_to_result(result, s, c);
	return (result);
}
