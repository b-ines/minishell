/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retokenize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:14:18 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/28 15:14:41 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

static t_token	*split_expand(char *final_token)
{
	t_token	*token_new;
	char	**split_token;
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
	return (token_new);
}

void	retokenize(t_token **token, t_token *curr, char *final_token,
				t_token *ret_node)
{
	t_token	*token_new;
	t_token	*token_cpy;
	t_token	*head;

	token_new = split_expand(final_token);
	token_cpy = curr->next;
	if (curr->prev != NULL)
	{
		curr = curr->prev;
		curr->next = token_new;
		token_new->prev = curr;
		ret_node = NULL;
	}
	else
	{
		(*token) = token_new;
		ret_node = NULL;
	}
	if (token_cpy != NULL)
	{
		head = *token;
		while (head->next != NULL)
			head = head->next;
		head->next = token_cpy;
		token_cpy->prev = head;
		ret_node = token_cpy;
	}
}
