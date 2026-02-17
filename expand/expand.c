/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:10 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/17 15:27:14 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include <stdlib.h>
#include <stdio.h>

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

static void	make_expand(t_token *token)
{
	char	*var;

	printf("Expand detected on: %s\n", token->token);
	/*Attention ca renvoie null si la variable n'existe a voir comment
	gere ca plus tard mais le shell lui nimprime pas juste la variable si elle nexiste pas*/
	var = getenv(&token->token[1]);
	free(token->token);
	token->token = var;
}

void	expand(t_token *token)
{
	printf("Step to expand\n");
	while (token != NULL)
	{
		if (is_expand(*token))
			make_expand(token);
		token = token->next;
	}
}
