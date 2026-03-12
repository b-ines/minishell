/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:14:18 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/12 15:02:11 by inbeaumo         ###   ########.fr       */
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

static t_token	*append_token_tail(t_token **token, t_token *token_cpy)
{
	t_token	*head;

	if (token_cpy == NULL)
		return (0);
	head = *token;
	while (head->next != NULL)
		head = head->next;
	head->next = token_cpy;
	token_cpy->prev = head;
	return (token_cpy);
}

t_token	*retokenize(t_token **token, t_token *curr, char *final_token)
{
	t_token	*token_new;
	t_token	*token_cpy;

	token_new = split_expand(final_token);
	token_cpy = curr->next;
	insert_new_tokens(token, curr, token_new);
	return (append_token_tail(token, token_cpy));
}
