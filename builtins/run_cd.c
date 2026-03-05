/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:30 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/05 15:13:10 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	get_arg_type(char *path)
{
	struct stat	buffer;

	stat(path, &buffer);
	if (S_ISDIR(buffer.st_mode))
		return (2);
	else if (S_ISREG(buffer.st_mode))
		return (1);
	else
		return (0);
}

void	cd_error(t_terminal *terminal, char *var, char *str)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(var, 2);
	ft_putendl_fd(str, 2);
	terminal->exit_status = 1;
}

void	change_dir(t_terminal *terminal, t_cmd *cmd)
{
	char	*curr_dir;
	char	new_dir[10000];

	curr_dir = get_value_by_key(terminal, "PWD");
	if (chdir(cmd->argv[1]) == -1)
		cd_error(terminal, cmd->argv[1], ": Permission denied");
	else
	{
		change_value_by_key(terminal, "OLDPWD", curr_dir);
		if (getcwd(new_dir, 10000) == NULL)
			perror("minishell: ");
		else
		{
			change_value_by_key(terminal, "PWD", new_dir);
			terminal->exit_status = 0;
		}
	}
}

void	run_cd(t_terminal *terminal, t_cmd *cmd)
{
	if (tab_size(cmd->argv) > 2)
		cd_error(terminal, cmd->argv[1], ": too many arguments");
	else if (cmd->argv[1] && get_arg_type(cmd->argv[1]) == 0)
		cd_error(terminal, cmd->argv[1], ": No such file or directory");
	else if (cmd->argv[1] && get_arg_type(cmd->argv[1]) == 1)
		cd_error(terminal, cmd->argv[1], ": Not a directory");
	else if (cmd->argv[1] && get_arg_type(cmd->argv[1]) == 2)
		change_dir(terminal, cmd);
}
