/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:28 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/26 18:12:36 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "../libft/libft.h"

int	get_index_by_key(t_terminal *terminal, char *key)
{
	int	i;

	i = 0;
	if (!key)
		return (-1);
	while (terminal->envp[i])
	{
		if (ft_strlen(terminal->envp[i]) >= ft_strlen(key)
			&& !ft_strncmp(terminal->envp[i], key, ft_strlen(key))
				&& (terminal->envp[i][ft_strlen(key)] == '='
					|| !terminal->envp[i][ft_strlen(key)]))	
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

int	change_value_by_key(t_terminal *terminal, char *key, char *new_value)
{
	int		index_to_change;
	char	*buffer;

	index_to_change = get_index_by_key(terminal, key);
	if (index_to_change != -1)
	{
		ft_free_malloc(terminal->envp[index_to_change]);
		terminal->envp[index_to_change] = 0;
		buffer = ft_strjoin(key, "=");
		terminal->envp[index_to_change] = ft_strjoin_free(buffer, new_value);
		return (1);
	}
	return (0);
}

