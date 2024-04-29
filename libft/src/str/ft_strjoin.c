/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:35:01 by mmoussou          #+#    #+#             */
/*   Updated: 2024/02/26 03:07:16 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*fstr;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	fstr = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fstr)
		return (NULL);
	ft_strlcpy(fstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(fstr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (fstr);
}

char	*ft_strjoin_free_s1(char *s1, const char *s2)
{
	char	*fstr;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	fstr = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fstr)
		return (NULL);
	ft_strlcpy(fstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(fstr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1[0])
		free(s1);
	return (fstr);
}

char	*ft_strjoin_free_s2(const char *s1, char *s2)
{
	char	*fstr;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	fstr = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fstr)
		return (NULL);
	ft_strlcpy(fstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(fstr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s2);
	return (fstr);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*fstr;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	fstr = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fstr)
		return (NULL);
	ft_strlcpy(fstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(fstr, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	free(s2);
	return (fstr);
}
