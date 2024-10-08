/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:46:57 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/13 17:01:12 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtins.h"

int	check_exit_value(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	if (!i)
		return (1);
	return (0);
}

void	exit_args_handler(char **argv, int ac, char **env_array, t_env *env)
{
	int	return_value;

	if (ac > 2)
	{
		ft_printf_fd(2, "minishell: exit: too many arguments\n");
		get_exit_code(1);
		return ;
	}
	return_value = ft_atoi(argv[1]);
	if (return_value == -1)
		return_value += 256;
	free_exit(env, env_array);
	exit(get_exit_code(return_value));
}

void	ft_exit(char **argv, int ac, char **env_array, t_env *env)
{
	printf("exit\n");
	if (ac < 2)
	{
		free_exit(env, env_array);
		exit(get_exit_code(-1));
	}
	if (check_exit_value(argv[1])
		|| (ft_atoi(argv[1]) % 10 != ft_atol(argv[1]) % 10))
	{
		ft_printf_fd(2,
			"minishell: exit: %s: numeric argument required\n", argv[1]);
		free_exit(env, env_array);
		exit(2);
	}
	else
		exit_args_handler(argv, ac, env_array, env);
}
