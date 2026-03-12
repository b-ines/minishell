/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_echo_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:51 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/05 15:15:02 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_nflag(char *str)
{
	int	i;

	if (!str || str[0] != '-')
		return (0);
	i = 1;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	run_echo(t_terminal *terminal, t_cmd *cmd, int fd)
{
	int	i;
	int	no_nl;

	i = 1;
	no_nl = 0;
	while (cmd->argv[i] && is_nflag(cmd->argv[i]))
	{
		no_nl = 1;
		i++;
	}
	while (cmd->argv[i])
	{
		ft_putstr_fd(cmd->argv[i], fd);
		if (cmd->argv[i + 1])
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (!no_nl)
		ft_putstr_fd("\n", fd);
	terminal->exit_status = 0;
}

void	run_pwd(t_terminal *terminal, t_cmd *cmd, int fd)
{
	char	buffer[10000];

	(void)cmd;
	if (getcwd(buffer, 10000) != NULL)
	{
		ft_putendl_fd(buffer, fd);
		terminal->exit_status = 0;
	}
	else
	{
		perror("minishell: pwd error");
		terminal->exit_status = 1;
	}
}
