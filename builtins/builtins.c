/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:21 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/24 11:51:19 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

//ptet gerer les redirections fd dans le run_builtins pour alleger

int is_builtins(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (1);
	else if (!ft_strcmp(cmd->argv[0], "cd"))
		return (1);
	else if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (1);
	else if (!ft_strcmp(cmd->argv[0], "export"))
		return (1);
	else if (!ft_strcmp(cmd->argv[0], "unset"))
		return (1);
	else if (!ft_strcmp(cmd->argv[0], "env"))
		return (1);
	else if (!ft_strcmp(cmd->argv[0], "exit"))
		return (1);
	else
		return (0);
}

void run_builtins(t_terminal *terminal, t_cmd *cmd)
{
	int	fd;

	fd = get_fd(cmd);
	if (fd < 0)
	{
		ft_putendl_fd("minishell: fd error", 2);
		terminal->exit_status = 1;
		return ;
	}
	if (!ft_strcmp(cmd->argv[0], "echo"))
		run_echo(terminal, cmd, fd);
	else if (!ft_strcmp(cmd->argv[0], "cd"))
		run_cd(terminal, cmd);
	else if (!ft_strcmp(cmd->argv[0], "pwd"))
		run_pwd(terminal, cmd, fd);
	else if (!ft_strcmp(cmd->argv[0], "export"))
		run_export(terminal, cmd, fd);
	else if (!ft_strcmp(cmd->argv[0], "unset"))
		run_unset(terminal, cmd);
	else if (!ft_strcmp(cmd->argv[0], "env"))
		run_env(terminal, cmd, fd);
	else if (!ft_strcmp(cmd->argv[0], "exit"))
		run_exit(terminal, cmd);
	// else
	// 	return ;
	if (cmd->outfile)
		close(fd);
}

void    builtins(t_terminal *terminal)
{
	t_cmd   *current;

	current = terminal->cmd_blocks;
	while (current)
	{
		if (is_builtins(current))
			run_builtins(terminal, current);
		current = current->next;
	}
}