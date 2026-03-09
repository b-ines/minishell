/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:10 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/09 18:31:19 by inbeaumo         ###   ########.fr       */
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
	if (str[i] == '_' || ft_isalpha(str[i]))
		i++;
	else
		return (0);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (i);

}

static t_expand_ctx is_expand(t_token *token) {
	int i;
	char	*tmp;

	i = 0;
	if (!token)
		return ((t_expand_ctx){i, 0, ENV});
	if (token->quote_flag == 1)
		return ((t_expand_ctx){i, 0, NONE});
	while (token->token[i] != '\0')
	{
		if (token->type == WORD)
		{
			if (token->quote_flag == 0 && token->token[i] == '$' && !token->token[i + 1] && token->next && token->next->quote_flag != 0)
				return ((t_expand_ctx){i, 0, ENV});
			else if (token->token[i] == '$' && (ft_isalpha(token->token[i + 1]) || token->token[i + 1] == '_'))
			{
				if ((i != 0 && (token->token[i - 1] != '\\')) || (i == 0))
					return ((t_expand_ctx){i + 1, expand_size(&token->token[i + 1]), ENV});
				else
				{ // cas pour pas faire lexpension si \ avant $
					tmp = ft_strdup(&token->token[i]);
					ft_free_malloc(token->token);
					token->token = tmp;
					return ((t_expand_ctx){i + 1, 0, NONE});
				}
			}
			else if (token->token[i] == '$' && token->token[i + 1] == '$')
				return ((t_expand_ctx){i + 1, 1, ENV});
			else if (token->token[i] == '$' && token->token[i + 1] == '?')
					return ((t_expand_ctx){i + 1, 1, EXIT_STATUS});
		}
		i++;
	}
	//printf("expand inconn\n");
	return ((t_expand_ctx){i, 0, NONE});
}

void expand(t_token **token, t_terminal term) {
  t_expand_ctx ctx;
  t_token *curr;

	//printf("Step to expand\n");
	curr = *token;
	while (curr != NULL) // while (ctx.ex_type != NONE) ? segfault
	{
		ctx = is_expand(curr);
		//while (curr && ctx.ex_type != NONE)
		//{
			if (ctx.ex_type == ENV)
				make_expand_env(token, curr, ctx.index, ctx.end, term.envp);
			else if (ctx.ex_type == EXIT_STATUS)
				make_exit_status(curr, term, ctx.index);
			else
			curr = curr->next;
		//}
		//	else
		// //if (curr)
		// else
		// 	curr = curr->next;
	}
}
