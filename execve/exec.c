/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:23:54 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/23 19:54:45 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		printf("%s ", args[i]);
		i++;
	}
	printf("\n");
}

/*static int	count_args(t_token *token)
{
	int	nb;

	nb = 0;
	while (token != NULL)
	{
		if (token->type == WORD)
			nb++;
		token = token->next;
	}
	return (nb);
}*/

/*static char	**token_to_argsv(t_token *token)
{
	char	**ret;
	int		i;

	// +2 pour le path et le NULL de fin
	ret = malloc(sizeof(char *) * count_args(token) + 2);
	i = 1;
	ret[0] = token->token;
	token = token->next;
	while (token != NULL)
	{
		if (token->type == SSPACE)
		{
			token = token->next;
			continue ;
		}
		if (token->type == WORD)
			ret[i] = ft_strdup(token->token);
		token = token->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}*/

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

void	exec(t_terminal *term)
{
	int		pid1;
	int		status;
	int		*fd;
	char	*path;
	int		cmdc;
	int		i;

	i = 0;
	cmdc = lst_size(term);
	fd = malloc(sizeof(int) * ((cmdc - 1) * 2));
	while (i < (cmdc - 1))
	{
		pipe(fd + i * 2);
		i++;
	}
	i = 0;
	while (term->cmd_blocks != NULL)
	{

		pid1 = fork();
		if (pid1 == 0) // C'est l'enfant
		{
			path = search_cmd(term->cmd_blocks->argv[0]);
			if (i != 0) // si ce nest pas la premiere commande
			{
				dup2(fd[(i - 1) * 2], 0);
			}
			if (i < (cmdc - 1)) // si ce nest pas la derniere commande
			{
				dup2(fd[i * 2 + 1], 1);
			}
			clear_fd(fd, cmdc);
			execve(path, term->cmd_blocks->argv, term->envp);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		term->cmd_blocks = term->cmd_blocks->next;
		i++;
	}
	clear_fd(fd, cmdc);
	while (wait(&status) > 0);
	term->exit_status = WEXITSTATUS(status);
}
