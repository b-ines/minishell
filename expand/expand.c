/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:10 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/13 16:09:14 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "../execve/exec.h"
#include "../execve/exec.h"
#include "../libft/libft.h"
#include "../main/main.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int	expand_size(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (1);
	if (str[i] == '_' || ft_isalpha(str[i]))
		i++;
	else
		return (0);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);
}

static t_expand_ctx	find_word_expand(t_token *token, int i)
{
	char	*tmp;

	if ((i != 0 && (token->token[i - 1] != '\\')) || (i == 0))
		return ((t_expand_ctx){i + 1, expand_size(&token->token[i + 1]), ENV});
	else
	{
		tmp = ft_strdup(&token->token[i]);
		ft_free_malloc(token->token);
		token->token = tmp;
		return ((t_expand_ctx){i + 1, 0, NONE});
	}
}

int	check_empty_expand(t_token *token, int i)
{
	if (token->quote_flag == 0 && token->token[i] == '$'
		&& !token->token[i + 1] && token->next && token->next->quote_flag != 0)
		return (1);
	return (0);
}

static t_expand_ctx	is_expand(t_token *token)
{
	int		i;

	i = 0;
	if (token && token->quote_flag == 1)
		return ((t_expand_ctx){i, 0, NONE});
	while (token && token->token[i] != '\0')
	{
		if (token->type == WORD)
		{
			if (check_empty_expand(token, i))
				return ((t_expand_ctx){i, 0, ENV});
			else if (token->token[i] == '$'
				&& (ft_isalnum(token->token[i + 1])
					|| token->token[i + 1] == '_'))
				return (find_word_expand(token, i));
			else if (token->token[i] == '$' && token->token[i + 1] == '$')
				return ((t_expand_ctx){i + 1, 1, ENV});
			else if (token->token[i] == '$' && token->token[i + 1] == '?')
				return ((t_expand_ctx){i + 1, 1, EXIT_STATUS});
		}
		i++;
	}
	return ((t_expand_ctx){i, 0, NONE});
}

void	expand(t_token **token, t_terminal term)
{
	t_expand_ctx	ctx;
	t_token			*curr;

	curr = *token;
	while (curr != NULL)
	{
		if (curr && curr->type == HERE_DOC)
		{
			if (curr->next && curr->next->next && curr->next->type == SSPACE)
				curr = curr->next->next;
			while (curr && curr->type == WORD)
				curr = curr->next;
		}
		ctx = is_expand(curr);
		if (curr && ctx.ex_type == ENV)
			curr = m_expand(token, curr, ctx, term.envp);
		else if (curr && ctx.ex_type == EXIT_STATUS)
			make_exit_status(curr, term, ctx.index);
		else if (curr)
			curr = curr->next;
	}
}
