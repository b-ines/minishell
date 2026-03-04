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
	int		fd;
	t_token	*filename;

	fd = -1;
	filename = token->next;
	if (filename && filename->type == SSPACE)
		filename = filename->next;
	if (!filename || filename->type != WORD)
		return (0);
	if (token->type == REDIR_INPUT)
		fd = open(filename->token, O_RDONLY);
	else if (token->type == REDIR_OUTPUT)
		fd = open(filename->token, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (token->type == APPEND)
		fd = open(filename->token, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (redir_error_msg(filename->token));
	close(fd);
	return (1);
}
