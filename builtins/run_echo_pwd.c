/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_echo_pwd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:51 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/23 16:15:09 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	is_nflag(char *str)
{
	int	i;

	if (!str || str[0] != '-')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void    run_echo(t_terminal *terminal, t_cmd *cmd, int fd)
{
	int i;
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

void    run_pwd(t_terminal *terminal, t_cmd *cmd, int fd)
{
	int i;

	i = 0;
	char buffer[10000];
	//jsp quoi daire des args encore
	(void)cmd;
	(void)fd;
	while (terminal->envp[i])
	{
		if (!ft_strncmp(terminal->envp[i], "PWD=", 4))
		{
			getcwd(buffer, 10000);
			printf("%s\n", buffer);
			// ft_putendl_fd(&terminal->envp[i][4], fd);
			terminal->exit_status = 0;
			// break ;
		}
		i++;
	}
}
