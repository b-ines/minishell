/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:59:11 by inbeaumo          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/02/28 16:07:48 by gchalmel         ###   ########.fr       */
=======
/*   Updated: 2026/02/26 17:57:04 by inbeaumo         ###   ########.fr       */
>>>>>>> branch_inb
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "../libft/libft.h"

t_token	*create_node(char *str, int quote_flag)
{
	t_token	*new_node;

	new_node = ft_malloc(sizeof(t_token));
	new_node->token = ft_strdup(str);
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
<<<<<<< HEAD
	ft_free_malloc(token);
=======
	free(token);
>>>>>>> branch_inb
}
