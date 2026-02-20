/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:40:10 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/20 00:51:01 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "expand.h"
// #include "../libft/libft.h"
// #include "../main/main.h"
// #include <stdlib.h>
// #include <stdio.h>

// static t_expand_ctx	is_expand(t_token token)
// {
// 	int	i;

// 	i = 0;
// 	if (token.quote_flag == 1)
// 		return ((t_expand_ctx){i, NONE});
// 	while (token.token[i] != '\0')
// 	{
// 		if (token.type == WORD)
// 		{
// 			if (token.token[i] == '$' && ft_isalpha(token.token[i + 1]))
// 				return ((t_expand_ctx){i + 1, ENV});
// 			else if (token.token[i] == '$' && token.token[i + 1] == '$')
// 				return ((t_expand_ctx){i + 1, ENV});
// 			else if (token.token[i] == '$' && token.token[i + 1] == '?')
// 				return ((t_expand_ctx){i + 1, EXIT_STATUS});
// 		}
// 		i++;
// 	}
// 	//printf("expand inconn\n");
// 	return (-1);
// }

// static void	make_expand_env(t_token *token, int index, t_terminal term)
// {
// 	char	*var;
// 	char	*final_token;
// 	int		len_before_dollar;
// 	size_t	len_var;

// 	printf("Expand detected on: %s\n", token->token);
// 	/*Attention ca renvoie null si la variable n'existe a voir comment
// 	gere ca plus tard mais le shell lui nimprime pas la variable si elle nexiste pas*/
// 	var = getenv(&token->token[index]);
// 	if (index > 1)
// 	{
// 		if (var == NULL)
// 			len_var = 0;
// 		else
// 			len_var = ft_strlen(var);
// 		len_before_dollar = ft_strlen_sep(token->token, '$');
// 		final_token = malloc(sizeof(char) * len_before_dollar
// 				+ len_var + 1);
// 		ft_strlcpy(final_token, token->token, len_before_dollar + 1);
// 		if (var != NULL)
// 			ft_strlcat(final_token, var, len_before_dollar + len_var + 1);
// 	}
// 	else
// 		final_token = var;
// 	free(token->token);
// 	token->token = final_token;
// }

// void	expand(t_token *token, t_terminal term)
// {
// 	t_expand_ctx	ctx;

// 	//printf("Step to expand\n");
// 	while (token != NULL)
// 	{
// 		ctx = is_expand(*token);
// 		if (ctx.ex_type == ENV)
// 			make_expand_env(token, ctx.index, term.envp);
// 		else if (ctx.ex_type == EXIT_STATUS)
// 			make_exit_status(token, term);
// 		token = token->next;
// 	}
// }
