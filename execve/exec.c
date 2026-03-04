/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:23:54 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/04 12:23:14 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// ajouter le check is a directory avant lexec
// ajouter creation de fichiers en casace (cat > outfile > outfile > outfile) ca ecrit que dans le dernier mais ca cree les autres

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
	int		output_fd;

	path = search_cmd(term, term->cmd_blocks->argv[0]);
	if (!path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(term->cmd_blocks->argv[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit(127) ;
	}
	if (is_builtins(term->cmd_blocks))
	{
		output_fd = get_output_fd(term->cmd_blocks, i, cmdc, fd);
		if (output_fd < 0)
			return ;
		run_builtins(term, term->cmd_blocks, output_fd);
		exit(term->exit_status);
	}
	if (!redir_management(term, i, cmdc, fd))
	{	
		clear_fd(fd, cmdc);
		return ;
	}
	clear_fd(fd, cmdc); // la il faut que les fd soient rediriges pour les builtins
	execve(path, term->cmd_blocks->argv, term->envp);
	perror("execve");
	exit(EXIT_FAILURE);

}


void	ft_create_pipe(t_cmd *cmd, int **fd, int cmdc)
{
	int	i;
	t_cmd	*current;

	i = 0;
	current = cmd;
	*fd = ft_malloc(sizeof(int) * ((cmdc - 1) * 2));
	while (current->next)
	{
		pipe(*fd + i * 2);
		current = current->next;
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
	int		output_fd;

	cmdc = lst_size(term);
	ft_create_pipe(term->cmd_blocks, &fd, cmdc);
	i = 0;
	if (cmdc == 1 && is_builtins(term->cmd_blocks))
	{
		output_fd = get_output_fd(term->cmd_blocks, &i, cmdc, fd);
		if (output_fd < 0)
			return ;
		run_builtins(term, term->cmd_blocks, output_fd);
		return ;
	}
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
