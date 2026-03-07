/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:49:57 by gabch             #+#    #+#             */
/*   Updated: 2026/03/05 12:49:08 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../libft/libft.h"
#include <stdlib.h>

/*
relative path (./a.out)
absolute path (ex /bin/ls)
cmd (ex: ls, echo, etc...)
*/

int	is_abs_or_rel_path(char *cmd)
{
	if (cmd[0] == '/' || cmd[0] == '.')
		return (1);
	return (0);
}

char	*search_cmd(t_terminal *term, char *cmd)
{
	char	**path;
	char	*abs_cmd;
	int		len_abs;
	int		i;

	if (is_abs_or_rel_path(cmd))
		return (cmd);
	if (!get_value_by_key(term, "PATH") || !cmd[0])
		return (0);
	path = ft_split(get_value_by_key(term, "PATH"), ':');
	i = 0;
	while (path[i] != NULL)
	{
		// +2 pour \0 et '/' entre path[i] et cmd
		len_abs = ft_strlen(path[i]) + ft_strlen(cmd) + 2;
		abs_cmd = ft_malloc(sizeof(char) * len_abs);
		ft_strlcpy(abs_cmd, path[i], len_abs);
		ft_strlcat(abs_cmd, "/", len_abs);
		ft_strlcat(abs_cmd, cmd, len_abs);
		if (access(abs_cmd, F_OK) == 0)
			return (abs_cmd);
		ft_free_malloc(abs_cmd);
		i++;
	}
	return (0);
}
