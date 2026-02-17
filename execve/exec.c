/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:23:54 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/17 23:46:31 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

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

static int	count_args(t_token *token)
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
}

static char	**token_to_argsv(t_token *token)
{
	char	**ret;
	int		i;

	// +2 pour le path et le NULL de fin
	ret = malloc(sizeof(char *) * count_args(token) + 2);
	i = 1;
	ret[0] = token->token;
	while (token != NULL)
	{
		if (token->type == WORD)
			ret[i] = ft_strdup(token->token);
		token = token->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	exec(t_token *token)
{
	int		id;
	char	**args;
	char	**env_path;

	// Pourquoi utiliser fork ?
	// Car execve remplace le processus courant donc si
	// cetait executer directement sans fork il aurait ecraser le minishell
	// et donc le programme se serait stopper tout seul a la fin de execve
	id = fork();
	if (id == 0) // C'est l'enfant
	{
		args = token_to_argsv(token);
		env_path = NULL;
		print_args(args);
		execve(args[0], args, env_path);
		perror("execve");
	}
	else // C'est le parent (minishell) donc on attend
	{
		waitpid(id, NULL, 0);
	}
}
