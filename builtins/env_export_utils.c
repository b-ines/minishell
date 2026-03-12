/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_export_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:52:18 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/12 17:52:19 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	get_index_by_key_e(t_terminal *terminal, char *key)
{
	int	i;

	i = 0;
	if (!key)
		return (-1);
	while (terminal->envp_export[i])
	{
		if (ft_strlen(terminal->envp_export[i]) >= ft_strlen(key)
			&& !ft_strncmp(terminal->envp_export[i], key, ft_strlen(key))
			&& (terminal->envp_export[i][ft_strlen(key)] == '='
			|| !terminal->envp_export[i][ft_strlen(key)]))
			return (i);
		i++;
	}
	return (-1);
}

int	change_value_by_key_e(t_terminal *terminal, char *key, char *new_v)
{
	int		index_to_change;
	char	*buffer;

	index_to_change = get_index_by_key_e(terminal, key);
	if (index_to_change != -1)
	{
		ft_free_malloc(terminal->envp_export[index_to_change]);
		terminal->envp_export[index_to_change] = 0;
		buffer = ft_strjoin(key, "=");
		terminal->envp_export[index_to_change] = ft_strjoin_free(buffer, new_v);
		return (1);
	}
	return (0);
}
