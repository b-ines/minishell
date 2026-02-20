/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:23:54 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/20 17:06:40 by gchalmel         ###   ########.fr       */
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
}

void	exec(t_token *token, t_terminal *term)
{
	int		id;
	int		status;
	char	*path;
	char	**args;

	id = fork();
	if (id == 0) // C'est l'enfant
	{
		path = search_cmd(token->token);
		args = token_to_argsv(token);
		printf("%s\n", path);
		print_args(args);
		execve(path, args, term->envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else // C'est le parent (minishell) donc on attend
	{
		waitpid(id, &status, 0);
		term->exit_status = WEXITSTATUS(status);
	}
}
