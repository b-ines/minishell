/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:59:11 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/10 17:05:06 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../libft/libft.h"

t_token	*create_node(char *str, int quote_flag)
{
	t_token	*new_node;

	new_node = ft_malloc(sizeof(t_token));
	if (new_node == NULL)
		return (NULL);
	new_node->token = ft_strdup(str);
	if (new_node->token == NULL)
		return (NULL);
	new_node->quote_flag = quote_flag;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void	ft_addback(t_token **all_t, char *str, int quote_flag)
{
	t_token	*new_node;
	t_token	*last;

	new_node = create_node(str, quote_flag);
	if (!(*all_t))
	{
		*all_t = new_node;
		return ;
	}
	last = *all_t;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

void	free_token_list(t_token **token)
{
	t_token	*temp;

	temp = *token;
	while (temp)
	{
		temp = *token;
		ft_free_malloc(temp);
		(*token) = (*token)->next;
	}
	ft_free_malloc(token);
}
