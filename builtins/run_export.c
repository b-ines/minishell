/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:15 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/24 16:59:11 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

//si strchr est null ya pas de egal donc jexport juste
//si jai 2 variables du meme nom il me la recreee quand meme

//a faire : pwd proteger le getcwd mais marche pas
//unset aussi jsp si ca enleve des 2

int	valid_arg_export(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);		
	if (!(ft_isalpha(str[0]) || str[0] == '_'))
		return (0);
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

char	*get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	key = ft_strndup(str, i);
	return (key);
}

char	*get_value(char *str)
{
	int		i;
	char	*value;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return (0);
	value = ft_strdup(&str[i]);
	return (value);
}

int	key_already_in_env(t_terminal *terminal, char *cmd)
{
	char	*new_key;
	char	*curr_key;
	int		i;

	i = 0;
	new_key = get_key(cmd);
	while (terminal->envp_export[i])
	{
		curr_key = get_key(terminal->envp_export[i]);
		if (ft_strcmp(new_key, curr_key) == 0)
		{
			ft_free_malloc(new_key);
			ft_free_malloc(curr_key);
			return (i);
		}
		ft_free_malloc(curr_key);
		i++;
	}
	ft_free_malloc(new_key);
	return (-1);
}

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
			ft_putendl_fd("': not a valid indentifier", 2);
			terminal->exit_status = 1;
		}
		else // je segault quand il faut changer une variable qui existe deja // ya les sans = dans env
		{
			if (key_already_in_env(terminal, cmd->argv[i]) != -1)
			{
				printf("la condition donne : %s\n", ft_strchr(cmd->argv[i], '='));
				if (!ft_strchr(cmd->argv[i], '='))
					break ;
				change_var(terminal, cmd->argv[i], 0);
				change_var(terminal, cmd->argv[i], 1);
			}
			else
			{
				if (!ft_strchr(cmd->argv[i], '='))
					append_var(terminal, terminal->envp, cmd->argv[i], 0);
				append_var(terminal, terminal->envp_export, cmd->argv[i], 1);
			}
		}
		i++;
	}
}
