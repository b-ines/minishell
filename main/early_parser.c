/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   early_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:03 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/23 15:16:51 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//jsp pourquoi mais tab x1 fais rien tab x2 affiche un truc

int	str_is_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	str_is_only_tab(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

int empty_cmd(t_terminal *terminal, char *line)
{
	if (!line[0] || str_is_only_space(line))
		return (1);
	else if (!ft_strncmp(line, ":", ft_strlen(line)))
	{
		terminal->exit_status = 0;
		return (1);
	}
	else if (str_is_only_tab(line))
	{
		terminal->exit_status = 0;
		return (1);
	}
	else if (!ft_strncmp(line, "!", ft_strlen(line)))
	{
		terminal->exit_status = 1;
		return (1);
	}
	else
		return (0);
}
