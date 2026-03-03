/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_env_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:55 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/24 16:56:01 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../libft/libft.h"

void    run_env(t_terminal *terminal, t_cmd *cmd, int fd)
{
	int i;

	i = 0;
	if (cmd->argv[1])
	{
		ft_putendl_fd("minishell: env: too many arguments", 2);
		terminal->exit_status = 1;
		return ;
	}
	while (terminal->envp[i])
		ft_putendl_fd(terminal->envp[i++], fd);
	terminal->exit_status = 0;
}

void	unset_envp(t_terminal *terminal, int rm_i)
{
	char **new_env;
	int	i;
	int	j;

	i = 0;
	j = 0;
	new_env = ft_malloc(tab_size(terminal->envp) * sizeof(char *));
	if (!new_env)
		return ; 
	while (terminal->envp[i])
	{
		if (i != rm_i)
			new_env[j++] = ft_strdup(terminal->envp[i]);
		i++;
	}
	new_env[j] = 0;
	ft_free_split(terminal->envp);
	terminal->envp = new_env;
}

void	unset_envp_export(t_terminal *terminal, int rm_i)
{
	char **new_env;
	int	i;
	int	j;

	i = 0;
	j = 0;
	new_env = ft_malloc(tab_size(terminal->envp_export) * sizeof(char *));
	if (!new_env)
		return ; 
	while (terminal->envp_export[i])
	{
		if (i != rm_i)
			new_env[j++] = ft_strdup(terminal->envp_export[i]);
		i++;
	}
	new_env[j] = 0;
	ft_free_split(terminal->envp_export);
	terminal->envp_export = new_env;
}

void    run_unset(t_terminal *terminal, t_cmd *cmd)
{
	int i;
	int	env_index;

	i = 1;
	if (tab_size(cmd->argv) == 1)
	{
		terminal->exit_status = 0;
		return ;
	}
	while (cmd->argv[i])
	{
		env_index = get_index_by_key(terminal, cmd->argv[i]);
		if (env_index != -1)
		{	
			unset_envp(terminal, env_index);
			unset_envp_export(terminal, env_index);
		}
		i++;
	}
	terminal->exit_status = 0;
}
