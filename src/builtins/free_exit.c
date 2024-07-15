/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:28:36 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/15 15:24:37 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_exit(t_env *env)
{
	rl_clear_history();
	ft_envclear(&env_l, free);
	ft_lstclear(get_list(NULL), &free_cmd);
}
