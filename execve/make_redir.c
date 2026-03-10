/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitz <kitz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:45:36 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/10 23:57:09 by kitz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	check_fds(t_cmd *cmd, int io_flag)
{
	if (io_flag == 0)
	{
		if (cmd->infile)
			return (1);
		else if (cmd->heredoc_list)
			return (1);
		return (0);
	}
	else
	{
		if (cmd->outfile)
			return (1);
		return (0);
	}
}

int	get_fd_exec(t_cmd *cmd, int io_flag)
{
	int	fd;

	fd = 0;
	if (io_flag == 0)
	{
		if (cmd->heredoc_list)
			fd = cmd->heredoc_fd;
		else if (cmd->infile)
			fd = open(cmd->infile, O_RDONLY);
	}
	else if (io_flag == 1)
	{
		if (cmd->append)
			fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (cmd->outfile)
			fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	return (fd);
}

int	fd_error(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	return (0);
}

int	redir_management(t_terminal *term, int *i, int cmdc, int *fd)
{
	int	redir_fd;

	if (check_fds(term->cmd_blocks, 0))
	{
		redir_fd = get_fd_exec(term->cmd_blocks, 0);
		if (redir_fd < 0)
			return (0);
		else
			dup2(redir_fd, 0);
		close(redir_fd);
	}
	else if (*i != 0)
		dup2(fd[(*i - 1) * 2], 0);
	if (check_fds(term->cmd_blocks, 1))
	{
		redir_fd = get_fd_exec(term->cmd_blocks, 1);
		if (redir_fd < 0)
			return (0);
		else
			dup2(redir_fd, 1);
		close(redir_fd);
	}
	else if (*i < (cmdc - 1))
		dup2(fd[*i * 2 + 1], 1);
	return (1);
}
