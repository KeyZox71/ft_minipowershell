/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:26 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/30 17:27:13 by adjoly           ###   ########.fr       */
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

bool	check_syntax(char *readline);
void	send_error(char *msg, char **argv);
bool	check_redir(t_list *redir);
t_cmd	*get_redir_fd(void *content);
t_list	*get_cmd_list(t_list *list);
void	open_redir(t_redirection *redir, t_cmd *cmd, t_redir_sign sign[2]);
char	**split_argv(char *readline);
char	*env_var_replace(char *readline, t_env *env);
size_t	get_size_with_env(char *readline, t_env *env);
size_t	strlen_till_char(char *s, int c);
bool	check_quote(char *readline);
t_quote	__is_quote(char c);
char	*search_for_next_quote(char *s, t_quote quote_type);
bool	check_pipe(char *readline);
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

/*
 *						ONLY FOR DEBUG TO BE REMOVED 
 */
void	print_quote_type(t_quote type);
void	print_redir_sign(t_redir_sign redir_sign);
void	print_token(t_token *token);
void	print_redir(t_redirection *redir);

#endif
