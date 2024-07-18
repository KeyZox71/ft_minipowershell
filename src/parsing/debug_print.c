#include "parsing.h"

void	print_quote_type(t_quote type)
{
	if (type == SINGLE)
		ft_putendl_fd("SINGLE", STDOUT_FILENO);
	else if (type == DOUBLE)
		ft_putendl_fd("DOUBLE", STDOUT_FILENO);
	else if (type == FALSE)
		ft_putendl_fd("FALSE", STDOUT_FILENO);
	else if (type == NOT_CLOSED)
		ft_putendl_fd("NOT_CLOSED", STDOUT_FILENO);
}

void	print_redir_sign(t_redir_sign redir_sign)
{
	if (redir_sign == HEREDOC)
		ft_putendl_fd("HEREDOC", STDOUT_FILENO);
	else if (redir_sign == INFILE)
		ft_putendl_fd("INFILE", STDOUT_FILENO);
	else if (redir_sign == OUTFILE)
		ft_putendl_fd("OUTFILE", STDOUT_FILENO);
	else if (redir_sign == OUT_APPEND)
		ft_putendl_fd("OUT_APPEND", STDOUT_FILENO);
}

void	print_redir(t_redirection *redir)
{
	ft_putstr_fd("file_name : ", STDOUT_FILENO);
	if (redir->file_name)
		ft_putendl_fd(redir->file_name, STDOUT_FILENO);
	ft_putstr_fd("", STDOUT_FILENO);
	print_redir_sign(redir->sign);
}

void	print_token(t_token *token)
{
	t_list	*tmp;

	tmp = token->redirection;
	while (tmp)
	{
		print_redir((t_redirection*)tmp->content);
		tmp = tmp->next;
	}
	ft_putendl_fd(token->argv, STDOUT_FILENO);
}

void	print_cmd(t_cmd *cmd)
{
	char	**tmp;

	tmp = cmd->argv;
	ft_putstr_fd("INFILE fd : ", STDOUT_FILENO);
	ft_putnbr_fd(cmd->infile, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putstr_fd("OUTFILE fd : ", STDOUT_FILENO);
	ft_putnbr_fd(cmd->outfile, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_putstr_fd("cmd : ", STDOUT_FILENO);
	ft_putendl_fd(cmd->cmd, STDOUT_FILENO);
	ft_putstr_fd("argv : ", STDOUT_FILENO);
	while (*tmp)
	{
		ft_putstr_fd(*tmp, STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		tmp++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}
