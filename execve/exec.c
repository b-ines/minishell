/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:23:54 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/17 17:37:51 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>



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
		env_path = ft_split(getenv("PATH"), ':');
		execve(token->token, );
	}
	else // C'est le parent (minishell) donc on attend
	{
		waitpid(id, NULL, 0);
	}
}
