/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:14:15 by adjoly            #+#    #+#             */
/*   Updated: 2024/06/26 12:45:41 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"

typedef enum s_redirection_sign
{
	INFILE,
	HEREDOC,
	OUTFILE,
	OUT_APPEND,
}	t_redirection_sign;

typedef struct s_redirection
{
	char				*file_name;
	t_redirection_sign	sign;
}	t_redirection;

typedef struct s_token
{
	char	*argv;
	t_list	*redirection;
}	t_token;

/**
 * @brief				Take a string and tell what type of redirect it is
 *
 * @param				A string that contain a redirection sign
 *
 * @return (t_redirection_sign)	The sign of the redirecition
 */
t_redirection_sign	__to_redir_sign(char *redir_sign);

/**
 * @brief				Take a string and split the filename and the redirect 
 *						sign
 *
 * @param redir_s		A string that contain a redirection
 *
 * @return (t_redirection)	The splited redirection
 */
t_redirection		*__to_redir(char *redir_s);

/**
 * @brief				Convert the raw command into a t_token that contains 
 *						the argv of the command an a linked list of redirection
 *
 * @param cmd			A string that contain the command to tokenize
 *
 * @return (t_token *)	The tokenized version of the command
 *						
 */
t_token				*__to_token(char *cmd);

/**
 * @brief				
 *
 * @param				The readline output
 *
 * @return (t_list *)	A linked lst of all the command splited
 *
 */
t_list				*__split_pipe(char *readline);

/**
 * @brief				Convert the readline output, split all command and put
 *						it in linked list of t_token (given by t_token function)
 *
 * @param	readline	The readline output
 *
 * @return	(t_list	*)	Linked list of t_token
 *						
 */
t_list				*tokenizer(char	*readline);	

#endif
