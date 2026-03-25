/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:55:22 by kitz              #+#    #+#             */
/*   Updated: 2026/03/25 16:43:32 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	get_builtin_fd(t_cmd *cmd, int *i, int cmdc, int *fd)
{
	int	output_fd;

	output_fd = 1;
	if (check_fds(cmd, 1))
	{
		output_fd = get_fd_exec(cmd, 1);
		if (output_fd < 0)
			return (fd_error(cmd->outfile));
	}
	else if (*i < (cmdc - 1))
		output_fd = fd[*i * 2 + 1];
	return (output_fd);
}

int	exec_single_builtin(t_terminal *term, int cmdc, int *fd, int *i)
{
	int	output_fd;

	if (cmdc == 1 && is_builtins(term->cmd_blocks))
	{
		if (!parse_files(term))
		{
			term->exit_status = 1;
			return (1);
		}
		output_fd = get_builtin_fd(term->cmd_blocks, i, cmdc, fd);
		if (output_fd < 0)
			return (1);
		run_builtins(term, term->cmd_blocks, output_fd, 0);
		if (term->cmd_blocks->heredoc_fd != -1)
		{
			close(term->cmd_blocks->heredoc_fd);
			term->cmd_blocks->heredoc_fd = -1;
		}
		return (1);
	}
	else
		return (0);
}

void	exec_piped_builtin(t_terminal *term, int cmdc, int *fd, int *i)
{
	if (is_builtins(term->cmd_blocks))
	{
		if (!redir_management(term, i, cmdc, fd))
		{
			clear_fd(fd, cmdc);
			ft_free_all_malloc();
			exit(1);
		}
		clear_fd(fd, cmdc);
		run_builtins(term, term->cmd_blocks, 1, 1);
		ft_free_all_malloc();
		exit(term->exit_status);
	}
}
