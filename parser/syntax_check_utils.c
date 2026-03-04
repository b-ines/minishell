/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:41:23 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/04 15:32:45 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	word_at_right(t_token *token)
{
	t_token	*current;

	current = token;
	if (!current->next)
		return (0);
	if (current->next->type == SSPACE)
		current = token->next;
	if (current->next && current->next->type == WORD)
		return (1);
	else
		return (0);
}

int	word_at_left(t_token *token)
{
	t_token	*current;

	current = token;
	if (!current->prev)
		return (0);
	if (current->prev->type == SSPACE)
		current = token->prev;
	if (current->prev && current->prev->type == WORD)
		return (1);
	else
		return (0);
}

int	pipe_check(t_token *token)
{
	if (!word_at_left(token))
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		return (0);
	}
	if (!(word_at_right(token) || (token->next && is_redir(token->next))))
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `|'", 2);
		return (0);
	}
	return (1);
}

//pour le  < pour message 4x<=< 5x<=2 + que 5< cest <<< 
int	redir_check(t_token *token)
{
	if (word_at_right(token))
		return (1);
	else if (!token->next)
	{
		ft_putstr_fd("minishell: syntax error near unexpected ", 2);
		ft_putendl_fd("token `newline'", 2);
		return (0);
	}
	if (token->next->type == SSPACE && token->next->next
		&& is_redir(token->next->next))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd(token->next->next->token, 2);
		ft_putendl_fd("'", 2);
		return (0);
	}
	else if (token->next->type != SSPACE && is_redir(token->next))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd(token->next->token, 2);
		ft_putendl_fd("'", 2);
		return (0);
	}
	return (1);
}
