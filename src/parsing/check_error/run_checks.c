/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:30:27 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/18 17:13:11 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error_msg.h"
#include <stdio.h>
#include <readline/history.h>

bool	run_checks(char *rl)
{
	if (!*rl)
		return (true);
	add_history(rl);
	if (check_syntax(rl))
		return (true);
	if (check_quote(rl))
		return (true);
	if (check_pipe(rl))
		return (true);
	return (false);
}
