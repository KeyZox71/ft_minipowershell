/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:20:22 by mmoussou          #+#    #+#             */
/*   Updated: 2024/06/03 15:26:03 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

char	**get_path(char *path);

/**
 * @brief				spawn a heredoc
 *
 * @param delimiter		a string representing the delimiter of the heredoc
 *
 * @return (int)		fd of a file containing the user's input, or -1 on error
 */
int		ft_heredoc(char *delimiter);

#endif
