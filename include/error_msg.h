/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:25:06 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/14 10:17:33 by mmoussou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

/**
 * Here we define all the error message
 */
# include <stdbool.h>

# define ERROR_SYNTAX "syntax error"
# define ERROR_NO_REDIR "need redirection file"
# define ERROR_NO_EOF "need delimiter to heredoc"
# define ERROR_NO_FILE "No such file or directory"
# define ERROR_CMD_PIPE "No command after pipe"
# define ERROR_NO_CMD "minishell : command not found: "

# define ERROR_COREDUMP "(core dumped)"

char	*get_program_name(char	*argv_one);
bool	send_error_parsing(char *msg);
bool	check_space(char *rl);

//free(*get_rl(NULL));

#endif
