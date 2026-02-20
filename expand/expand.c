/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:10 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/20 16:51:33 by gchalmel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "../libft/libft.h"
#include "../main/main.h"
#include "../execve/exec.h"
#include <stdlib.h>
#include <stdio.h>

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
			else if (token.token[i] == '$' && token.token[i + 1] == '?')
				return ((t_expand_ctx){i + 1, EXIT_STATUS});
		}
		i++;
	}
	printf("expand inconn\n");
	return ((t_expand_ctx){i, NONE});
}

void	expand(t_token *token, t_terminal term)
{
	t_expand_ctx	ctx;

	printf("Step to expand\n");
	while (token != NULL)
	{
		ctx = is_expand(*token);
		if (ctx.ex_type == ENV)
			make_expand_env(token, ctx.index, term.envp);
		else if (ctx.ex_type == EXIT_STATUS)
			make_exit_status(token, term);
		token = token->next;
	}
}
