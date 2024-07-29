/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/29 19:24:08 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "tokenizer.h"
# include "env.h"

typedef struct s_cmd
{
	char	*cmd;
	char	**argv;
	int		infile;
	int		outfile;
}	t_cmd;

typedef enum s_quote
{
	NOT_CLOSED = -1,
	FALSE,
	SINGLE = 39,
	DOUBLE = 34
}	t_quote;

t_cmd	*get_redir_fd(void *content, t_list *tmp);
t_list	*get_cmd_list(t_list *list);
void	open_redir(t_redirection *redir, t_cmd *cmd, t_redir_sign sign[2]);

/**
 * @brief				Take a string and a character and return the lengh
 *						until the given character
 *
 * @param s				The string
 * @param				The character the lengh stops at
 *
 * @return (size_t)		The lengh until the given character
 */
size_t	strlen_till_char(char *s, int c);

bool	check_quote(char *readline);
bool	check_syntax(char *readline);
bool	check_redir(t_list *redir);
bool	check_argv(t_list *token);
bool	check_wspace(char *readline);
/**
 * @brief				Take the readline output and check if all the pipe 
 *						a command after them
 *
 * @param				The readline output
 *
 * @return (bool)		A boolean of whether or not there is an error
 */
bool	check_pipe(char *readline);

/**
 * @brief				Take the readline output and split it into an argv 
 *						while taking into account quotes
 *
 * @param				The readline output
 *
 * @return (char **)	The argv of the command
 */
char	**split_argv(char *readline);

/**
 * @brief				Take the argv of a command a split the argv and the
 *						command it self
 *
 * @param cmd_av		The full argv of the command
 *
 * @return (t_cmd *)	cmd and argv splited into a struct
 */
t_cmd	*split_cmd(char *cmd_av, t_cmd *cmd);

/**
 * @brief				Take a string and an index and check if the character 
 *						at the index is in quote
 *
 * @param s				The string to search in
 * @param i				The index of the character to check
 *
 * @return (t_quote)	The type of quote if between, if not return FALSE or 
 *						NOT_CLOSED if the quote is not closed
 */
t_quote	is_inquote(char	*s, size_t i);

/**
 * @brief				Take a character and check if it is a quote and return 
 *						the type of quote
 *
 * @param c				The character to check
 *
 * @return (t_quote)	The type of quote or FALSE
 */
t_quote	__is_quote(char c);

/**
 * @brief				Take a string and a quote type and return the pointer to
 *						the next quote
 *
 * @param s				A pointer to a string
 * @param quote_type	A type of quote
 *
 * @return (char *)		A pointer to the next quote
 */
char	*search_for_next_quote(char *s, t_quote quote_type);

/**
 * @brief				Take the readline output and the env and replace all the 
 *						$("variable") by their variable content
 *
 * @param readline		The readline output
 * @param env			The env
 *
 * @return (char *)		The curated string
 */
char	*env_var_replace(char *readline, t_env *env);
size_t	get_size_with_env(char *readline, t_env *env);
size_t	strlen_till_notalnum(char *s);

#endif
