/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitz <kitz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:56:45 by kitz              #+#    #+#             */
/*   Updated: 2026/03/10 23:57:04 by kitz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	lst_size(t_terminal *term)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	tmp = term->cmd_blocks;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	clear_fd(int *fd, int cmdc)
{
	int	j;

	j = 0;
	while (j < (cmdc - 1) * 2)
		close(fd[j++]);
}

int	ft_create_pipe(t_cmd *cmd, int **fd, int cmdc)
{
	int		i;
	t_cmd	*current;

	i = 0;
	current = cmd;
	*fd = ft_malloc(sizeof(int) * ((cmdc - 1) * 2));
	if (*fd == NULL)
		return (-1);
	while (current->next)
	{
		if (pipe(*fd + i * 2) == -1)
		{
			while (i > 0)
			{
				i--;
				close((*fd)[i * 2]);
				close((*fd)[i * 2 + 1]);
			}
			return (-1);
		}
		current = current->next;
		i++;
	}
	return (0);
}
