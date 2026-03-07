/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:15 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/06 13:32:39 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	append_var(t_terminal *terminal, char **env, char *cmd, int env_flag)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = ft_malloc((tab_size(env) + 2) * sizeof(char *));
	if (!new_env)
		return ;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(cmd);
	new_env[i + 1] = 0;
	ft_free_split(env);
	if (env_flag == 0)
		terminal->envp = new_env;
	else if (env_flag == 1)
		terminal->envp_export = new_env;
}

void	change_var(t_terminal *terminal, char *cmd, int env_flag)
{
	int		index_to_change;

	index_to_change = key_already_in_env(terminal, cmd);
	if (env_flag == 0)
	{
		ft_free_malloc(terminal->envp[index_to_change]);
		terminal->envp[index_to_change] = 0;
		terminal->envp[index_to_change] = ft_strdup(cmd);
	}
	if (env_flag == 1)
	{
		ft_free_malloc(terminal->envp_export[index_to_change]);
		terminal->envp_export[index_to_change] = 0;
		terminal->envp_export[index_to_change] = ft_strdup(cmd);
	}
}

void	change_envs(t_terminal *terminal, t_cmd *cmd, int i)
{
	if (key_already_in_env(terminal, cmd->argv[i]) != -1)
	{
		if (!ft_strchr(cmd->argv[i], '='))
			return ;
		change_var(terminal, cmd->argv[i], 0);
		change_var(terminal, cmd->argv[i], 1);
	}
	else
	{
		if (ft_strchr(cmd->argv[i], '=') != NULL)
			append_var(terminal, terminal->envp, cmd->argv[i], 0);
		append_var(terminal, terminal->envp_export, cmd->argv[i], 1);
	}
}

void	run_export(t_terminal *terminal, t_cmd *cmd, int fd)
{
	int		i;

	i = 1;
	if (!cmd->argv[1])
		print_sorted_envp(terminal->envp_export, fd);
	terminal->exit_status = 0;
	while (cmd->argv[i])
	{
		if (!valid_arg_export(cmd->argv[i]))
		{
			ft_putstr_fd("mimishell: export: `", 2);
			ft_putstr_fd(cmd->argv[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			terminal->exit_status = 1;
		}
		else
			change_envs(terminal, cmd, i);
		i++;
	}
}
