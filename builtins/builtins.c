/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:21 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/05 15:00:17 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	tab_size(char **argv)
{
	int	i;

	if (!argv || !argv[0])
		return (0);
	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	is_builtins(t_cmd *cmd)
{
	if (!cmd->argv || !cmd->argv[0])
		return (0);
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

void	run_builtins(t_terminal *terminal, t_cmd *cmd, int fd)
{
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
	if (fd != 1)
		close(fd);
}
