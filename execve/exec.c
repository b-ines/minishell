/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:23:54 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/17 17:45:25 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

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
}

static char	**token_to_argsv(t_token *token)
{
	char	**ret;
	int		i;

	ret = malloc(sizeof(char *) * count_args(token) + 1);
	i = 0;
	while (token != NULL)
	{
		if (token->type == WORD)
			ret[i] = ft_strdup(token->token);
		token = token->next;
		i++;
	}
}

void	exec(t_token *token)
{
	int		id;
	char	*path;
	char	**args;
	char	**env_path;

	// Pourquoi utiliser fork ?
	// Car execve remplace le processus courant donc si
	// cetait executer directement sans fork il aurait ecraser le minishell
	// et donc le programme se serait stopper tout seul a la fin de execve
	id = fork();
	if (id == 0) // C'est l'enfant
	{
		path = token->token;
		token = token->next;
		env_path = ft_split(getenv("PATH"), ':');
		execve(token->token, args, env_path);
	}
	else // C'est le parent (minishell) donc on attend
	{
		waitpid(id, NULL, 0);
	}
}
