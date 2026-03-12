/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:42:33 by gchalmel          #+#    #+#             */
/*   Updated: 2026/03/10 15:55:38 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "../parser/parser.h"

t_token	*del_token(t_token **token, t_token *curr)
{
	t_token	*next;

	next = curr->next;
	if (curr->prev)
		curr->prev->next = curr->next;
	else
		*token = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	return (next);
}

int	ambiguous_arg(t_token *curr, char *var, t_expand_ctx ctx)
{
	int	len_a;
	int	len_b;

	len_b = ft_strlen_sep(curr->token, '$');
	len_a = ft_strlen(curr->token) - (len_b + ctx.end + 1);
	if (!var && ((curr->prev && is_redir(curr->prev)) || (curr->prev
				&& curr->prev->type == SSPACE && curr->prev->prev
				&& is_redir(curr->prev->prev))) && len_b == 0 && len_a == 0)
	{
		if (curr->quote_flag == 2)
			curr->token = ft_strdup("");
		else
			curr->token = ft_strjoin("|", curr->token);
		return (1);
	}
	return (0);
}

char	*get_final_token(t_token *curr, t_expand_ctx ctx, char **envp)
{
	char	*var;
	char	*final_token;
	int		len_b;
	size_t	len_var;
	int		len_a;

	var = ft_getenv(envp, ft_strndup(&curr->token[ctx.index], ctx.end));
	len_var = ft_strlen(var);
	len_b = ft_strlen_sep(curr->token, '$');
	len_a = ft_strlen(curr->token) - (len_b + ctx.end + 1);
	final_token = ft_malloc(sizeof(char) * (len_b + len_var + len_a + 1));
	ft_strlcpy(final_token, curr->token, len_b + 1);
	if (var != NULL)
		ft_strlcat(final_token, var, len_b + len_var + 1);
	final_token = ft_strjoin(final_token, &curr->token[len_b + ctx.end + 1]);
	return (final_token);
}

t_token	*m_expand(t_token **token, t_token *curr, t_expand_ctx ctx, char **envp)
{
	char	*final_token;
	char	*to_expand;

	to_expand = ft_strndup(&curr->token[ctx.index], ctx.end);
	final_token = get_final_token(curr, ctx, envp);
	if (ambiguous_arg(curr, ft_getenv(envp, to_expand), ctx))
		return (curr->next);
	if ((!final_token || !final_token[0]) && curr->quote_flag == 0)
		return (del_token(token, curr));
	if (curr->quote_flag == 0)
	{
		retokenize(token, curr, final_token);
		if (ft_strchr(final_token, '$'))
			return ((*token));
		return (((*token)->next));
	}
	else
	{
		ft_free_malloc(curr->token);
		curr->token = final_token;
		if (ft_strchr(final_token, '$'))
			return (curr);
		return (curr->next);
	}
}

void	make_exit_status(t_token *token, t_terminal term, int index)
{
	char	*var;
	char	*final_token;
	int		len_before_dollar;
	size_t	len_var;

	var = ft_itoa(term.exit_status);
	if (token->token[index + 1] != '\0')
		var = ft_strjoin(var, &token->token[index + 1]);
	if (index > 1)
	{
		len_var = ft_strlen(var);
		len_before_dollar = ft_strlen_sep(token->token, '$');
		final_token = ft_malloc(sizeof(char) * len_before_dollar + len_var + 1);
		if (final_token == NULL)
			return ;
		ft_strlcpy(final_token, token->token, len_before_dollar + 1);
		if (var != NULL)
			ft_strlcat(final_token, var, len_before_dollar + len_var + 1);
	}
	else
		final_token = var;
	ft_free_malloc(token->token);
	token->token = final_token;
}
