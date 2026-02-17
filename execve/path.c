/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:49:57 by gabch             #+#    #+#             */
/*   Updated: 2026/02/18 00:19:54 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdlib.h>

/*
relative path (./a.out)
absolute path (ex /bin/ls)
cmd (ex: ls, echo, etc...)
*/
char	*search_cmd(char *cmd)
{
	char	**path;
	char	*abs_cmd;
	int		len_abs;
	int		i;

	path = ft_split(getenv("PATH"), ':');
	i = 0;
	while (path[i] != NULL)
	{
		// +2 pour \0 et '/' entre path[i] et cmd
		len_abs = ft_strlen(path[i]) + ft_strlen(cmd) + 2;
		abs_cmd = malloc(sizeof(char) * len_abs);
		ft_strlcpy(abs_cmd, path[i], len_abs);
		ft_strlcat(abs_cmd, "/", len_abs);
	}
}
