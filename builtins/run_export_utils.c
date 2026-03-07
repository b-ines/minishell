/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_export_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:32:37 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/05 15:37:16 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
	new_key = 0;
	curr_key = 0;
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
