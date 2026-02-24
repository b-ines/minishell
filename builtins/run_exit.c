/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:58 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/24 11:30:47 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_arg(char *str)
{
	int	signe;

	signe = 0;
	if (!ft_str_isdigit(str))
		return (0);
	if (str[0] == '-')
		signe = 1;
	if (ft_strlen(str) < 19)
		return (1);
	if ((ft_strlen(str) > 19 && signe == 0) || (ft_strlen(str) > 20 && signe == 1)) 
		return (0);
	if (signe == 1)
	{
		if (ft_strncmp(str, "-9223372036854775808", 20) > 0)	
			return (0);
	}
	if (ft_strncmp(str, "9223372036854775807", 19) > 0)	
			return (0);
	return (1);
}

void    run_exit(t_terminal *terminal, t_cmd *cmd)
{
	ft_putstr_fd("exit\n", 1);
	if (!cmd->argv[1])
		exit(0);
	if (cmd->argv[1] && !valid_arg(cmd->argv[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->argv[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	 	exit (2);
	}
	else if (tab_size(cmd->argv) > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	 	terminal->exit_status = 1;
	 	return ;
	}
	else
		exit(ft_atol(cmd->argv[1]) % 256);
}
