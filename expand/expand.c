/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:10 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/20 15:39:29 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "../libft/libft.h"
#include "../main/main.h"
#include "../execve/exec.h"
#include <stdlib.h>
#include <stdio.h>

/*
return index of expand
*/
static int	ft_strlen_sep(char *s, char fin)
{
	int	i;

	i = 0;
	while (s[i] != fin)
		i++;
	return (i);
}

static t_expand_ctx	is_expand(t_token token)
{
	int	i;

	i = 0;
	if (token.quote_flag == 1)
		return ((t_expand_ctx){i, NONE});
	while (token.token[i] != '\0')
	{
		if (token.type == WORD)
		{
			if (token.token[i] == '$' && ft_isalpha(token.token[i + 1]))
				return ((t_expand_ctx){i + 1, ENV});
			else if (token.token[i] == '$' && token.token[i + 1] == '$')
				return ((t_expand_ctx){i + 1, ENV});
		}
		i++;
	}
	printf("expand inconn\n");
	return ((t_expand_ctx){i, NONE});
}

char	*ft_getenv(char **envp, char *var)
{
	int	i;
	int	j;

	i = 0;
	printf("%s\n", var);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) == 0)
			break ;
		i++;
	}
	j = 0;
	while (envp[i] != NULL && envp[i][j])
	{
		if (envp[i][j] == '=')
			return (&envp[i][j + 1]);
		j++;
	}
	return (NULL);
}

static void	make_expand_env(t_token *token, int index, char **envp)
{
	char	*var;
	char	*final_token;
	int		len_before_dollar;
	size_t	len_var;

	printf("Expand detected on: %s\n", token->token);
	var = ft_getenv(envp, &token->token[index]);
	if (index > 1)
	{
		if (var == NULL)
			len_var = 0;
		else
			len_var = ft_strlen(var);
		len_before_dollar = ft_strlen_sep(token->token, '$');
		final_token = malloc(sizeof(char) * len_before_dollar
				+ len_var + 1);
		ft_strlcpy(final_token, token->token, len_before_dollar + 1);
		if (var != NULL)
			ft_strlcat(final_token, var, len_before_dollar + len_var + 1);
	}
	else
		final_token = var;
	free(token->token);
	token->token = final_token;
}

void	expand(t_token *token, t_terminal term)
{
	t_expand_ctx	index_expand;

	printf("Step to expand\n");
	while (token != NULL)
	{
		index_expand = is_expand(*token);
		if (index_expand.ex_type == ENV)
			make_expand_env(token, index_expand.index, term.envp);
		token = token->next;
	}
}
