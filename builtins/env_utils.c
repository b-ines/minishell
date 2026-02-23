/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:28 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/23 18:50:22 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	get_index_by_key(t_terminal *terminal, char *key)
{
	int	i;

	i = 0;
	while (terminal->envp[i])
	{
		if (!ft_strncmp(terminal->envp[i], key, ft_strlen(key)) && terminal->envp[i][ft_strlen(key)] == '=')	
			return (i);
		i++;
	}
	return (-1);
}

char	*get_key_by_index(t_terminal *terminal, int index)
{
	int		i;
	char	*key;

	i = 0;
	while (terminal->envp[index][i] && terminal->envp[index][i] != '=')
		i++;
	key = ft_strndup(terminal->envp[index], i);
	return (key);
}

//pour linstant il me semble que ca sert a rien
char	*get_value_by_key(t_terminal *terminal, char *key)
{
	(void)terminal;
	int	i;
	char	*value;

	i = get_index_by_key(terminal, key);

	if (i == -1)
		return (0);
	value = ft_strchr(terminal->envp[i], '=');
	if (!value)
		return (0);
	return (value + 1);
}

void	change_value_by_key(t_terminal *terminal, char *key, char *new_value)
{
	int		i;
	int		index_to_change;
	char	*buffer;

	i = 0;
	index_to_change = get_index_by_key(terminal, key);
	while (terminal->envp[i])
	{
		if (i == index_to_change)
		{
			free(terminal->envp[i]);
			terminal->envp[i] = 0;
			buffer = ft_strjoin(key, "=");
			terminal->envp[i] = ft_strjoin_free(buffer, new_value);
		}
		i++;
	}
}

