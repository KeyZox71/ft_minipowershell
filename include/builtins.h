/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:05:18 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/25 17:01:43 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "env.h"

# define PATH_MAX_LEN 4096

void	ft_pwd(void);
void	ft_cd(t_env *env, char *args);
char	*ret_cwd(void);

#endif
