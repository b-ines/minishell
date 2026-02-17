/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:10 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/17 15:07:16 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

static int	is_expand(t_token token)
{
	if (token.type == WORD)
	{
		if (token.quote_flag == 1)
			return (0);
		if (token.token[0] == '$')
			return (1);
	}
	return (0);
}

void	expand(t_token *token)
{
	while (token != NULL)
	{
		if (is_expand(*token))
			return ;
		token = token->next;
	}
}
