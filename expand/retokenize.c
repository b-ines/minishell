/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:14:18 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/13 15:26:26 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

static t_token	*split_expand(char *final_token)
{
	t_token	*token_new;
	char	**split_token;
	t_token	*current;
	int		i;

	token_new = NULL;
	split_token = ft_split(final_token, ' ');
	i = 1;
	ft_addback(&token_new, split_token[0], 0);
	while (split_token[i] != NULL)
	{
		ft_addback(&token_new, " ", 0);
		ft_addback(&token_new, split_token[i++], 0);
	}
	set_type(&token_new);
	current = token_new;
	while (current)
	{
		if (current->type != SSPACE)
		current->type = WORD;
		current = current->next;
	}
	return (token_new);
}

static void	insert_new_tokens(t_token **token, t_token *curr, t_token *tok_new)
{
	if (curr->prev != NULL)
	{
		curr = curr->prev;
		curr->next = tok_new;
		tok_new->prev = curr;
	}
	else
		(*token) = tok_new;
}

t_token	*retokenize(t_token **token, t_token *curr, char *final_token)
{
	t_token	*token_new;
	t_token	*token_cpy;
	t_token	*tail;

	token_new = split_expand(final_token);
	token_cpy = curr->next;
	if (!token_new)
	{
		if (curr->prev)
			curr->prev->next = token_cpy;
		else
			*token = token_cpy;
		if (token_cpy)
			token_cpy->prev = curr->prev;
		return (token_cpy);
	}
	insert_new_tokens(token, curr, token_new);
	tail = token_new;
	while (tail->next)
		tail = tail->next;
	tail->next = token_cpy;
	if (token_cpy)
		token_cpy->prev = tail;
	return (token_new);
}
