/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:32:29 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/04 15:35:29 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// int	get_fd_exec(t_cmd *cmd, int io_flag)
// {
// 	int	fd;

// 	if (io_flag == 0)
// 	{
// 		if (cmd->here_doc_delim)
// 			fd = cmd->heredoc_fd;
// 		else if (cmd->infile)
// 			fd = open(cmd->infile, O_RDONLY);
// 	}
// 	else if (io_flag == 1)
// 	{
// 		if (cmd->append)	
// 			fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 		else if (cmd->outfile)
// 			fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	}
// 	return (fd);
// }

int	redir_error_msg(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	return (0);
}

int	make_redir(t_token *token)
{
	int	fd;
	if (token->type == REDIR_INPUT)
	{
		if (token->next && token->next->type == SSPACE)
			token = token->next;
		if (token->next && token->next->type == WORD)
			fd = open(token->next->token, O_RDONLY);
		if (fd < 0)
			return (redir_error_msg(token->next->token));
	}
	else if (token->type == REDIR_OUTPUT)
	{
		if (token->next && token->next->type == SSPACE)
			token = token->next;
		if (token->next && token->next->type == WORD)
			fd = open(token->next->token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			return (redir_error_msg(token->next->token));
	}
	else if (token->type == APPEND)
	{
		if (token->next && token->next->type == SSPACE)
			token = token->next;
		if (token->next && token->next->type == WORD)
			fd = open(token->next->token, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
			return (redir_error_msg(token->next->token));
	}
	close(fd);
	return (1);
}
