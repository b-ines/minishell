/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:58:18 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/27 14:01:55 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	tab_size(char **argv)
{
	int	i;

	if (!argv || !argv[0])
		return (0);
	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	get_fd(t_cmd *cmd)
{
	if (cmd->outfile)
	{
		if (cmd->append)
			return (open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644));
		else
			return (open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	}
	else
		return (1);
}
