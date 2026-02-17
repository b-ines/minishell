/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:10 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/17 15:14:53 by gchalmel         ###   ########.fr       */
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

	var = getenv(token->token);
	free(token->token);
	token->token = var;
}

void	expand(t_token *token)
{
	while (token != NULL)
	{
		if (is_expand(*token))
			make_expand(token);
		token = token->next;
	}
}
