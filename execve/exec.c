/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:23:54 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/24 14:59:28 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

void	ft_execve(t_terminal *term, int *i, int cmdc, int *fd)
{
	char	*path;

	path = search_cmd(term->cmd_blocks->argv[0]);
	if (*i != 0) // si ce nest pas la premiere commande
	{
		dup2(fd[(*i - 1) * 2], 0);
	}
	if (*i < (cmdc - 1)) // si ce nest pas la derniere commande
	{
		dup2(fd[*i * 2 + 1], 1);
	}
	clear_fd(fd, cmdc);
	execve(path, term->cmd_blocks->argv, term->envp);
	perror("execve");
	exit(EXIT_FAILURE);

}

void	ft_create_pipe(int **fd, int cmdc)
{
	int	i;

	i = 0;
	*fd = ft_malloc(sizeof(int) * ((cmdc - 1) * 2));
	while (i < (cmdc - 1))
	{
		pipe(*fd + i * 2);
		i++;
	}
}

void	exec(t_terminal *term)
{
	int		pid1;
	int		status;
	int		*fd;
	int		cmdc;
	int		i;

	cmdc = lst_size(term);
	ft_create_pipe(&fd, cmdc);
	i = 0;
	while (term->cmd_blocks != NULL)
	{
		pid1 = fork();
		if (pid1 == 0) // C'est l'enfant
			ft_execve(term, &i, cmdc, fd);
		term->cmd_blocks = term->cmd_blocks->next;
		i++;
	}
	clear_fd(fd, cmdc);
	while (wait(&status) > 0);
	term->exit_status = WEXITSTATUS(status);
}
