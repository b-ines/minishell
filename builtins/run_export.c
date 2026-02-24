/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:15 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/23 19:05:22 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

//export tout seul ca print trie par ascii ET AVEC GUILLEMETS
//export Hola ca fait une var hola sans =
//export "" ca fait not a valid indentifier
//juste 0 c invalid jsp ourquoi
//si yen a un invalid ca continue quand meme un message pour toutes les erreurs
//dans la value il peut y avoir des =
//je peux faire une copie qui malloc le nombre de str mais pas les str plus leger
//si strchr est null ya pas de egal donc jexport juste

//jai pas pris en compte si ya des guillemts mais jcrois ca marche
//si jai 2 variables du meme nom il me la recreee quand meme

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

char	**env_cpy(char	**src)
{
	char	**dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char *) * (tab_size(src) + 1));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
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

int	export_in_envp_index(t_terminal *terminal, char *cmd)
{
	char	*new_key;
	char	*curr_key;
	int		i;

	i = 0;
	new_key = get_key(cmd);
	while (terminal->envp[i])
	{
		curr_key = get_key(terminal->envp[i]);
		if (!ft_strcmp(new_key, curr_key))
		{
			free(new_key);
			free(curr_key);
			return (i);
		}
		free(curr_key);
		i++;
	}
	free(new_key);
	return (0);
}

void	append_var(t_terminal *terminal, char *cmd)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = malloc((tab_size(terminal->envp) + 2) * sizeof(char *));
	if (!new_env)
		return ;
	while (terminal->envp[i])
	{	
		new_env[i] = ft_strdup(terminal->envp[i]);
		i++;
	}
	new_env[i] = ft_strdup(cmd);
	new_env[i + 1] = 0;
	ft_free_split(terminal->envp);
	terminal->envp = new_env;
}

char	**env_cpy_sorted(char **envp)
{
	int		i;
	int		j;
	char	**env;
	char	*key;
	char	*next_key;

	i = 0;
	env = env_cpy(envp);
	while (i < tab_size(envp) - 1)
	{
		j = 0;
		while (j < tab_size(envp) - i - 1)
		{
			key = get_key(env[j]);
			next_key = get_key(env[j + 1]);
			if (ft_strcmp(key, next_key) > 0)
				ft_swap_ptr((void *)env[j], (void *)env[j + 1]);
			free(key);
			free(next_key);
			j++;
		}
		i++;
	}
	return (env);
}

void	print_sorted_envp(t_terminal *terminal)
{
	char	**env_cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env_cpy = env_cpy_sorted(terminal->envp);
	while (env_cpy[i])
	{
		j = 0;
		printf("export ");
		while (env_cpy[i][j] && env_cpy[i][j] != '=')
			printf("%c", env_cpy[i][j++]);
		if (env_cpy[i][j] && env_cpy[i][j] == '=')
		{
			printf("%c\"", env_cpy[i][j++]);
			while (env_cpy[i][j])
				printf("%c", env_cpy[i][j++]);
			printf("\"");
		}
		printf("\n");
		i++;
	}
	ft_free_split(env_cpy);
}

void	run_export(t_terminal *terminal, t_cmd *cmd)
{
	int	i;
	char	*key;

	i = 1;
	if (!cmd->argv[1])
		print_sorted_envp(terminal);
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
		else
		{	
			key = get_key(cmd->argv[i]);
			if (get_index_by_key(terminal, cmd->argv[i]) != -1)
				change_value_by_key(terminal, key, get_value_by_key(terminal, key));
			else
				append_var(terminal, cmd->argv[i]);
			free(key);
		}
		i++;
	}
}
