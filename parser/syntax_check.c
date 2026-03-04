/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:43 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/04 15:27:07 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_redir(t_token *token)
{
	if (token->type == REDIR_INPUT || token->type == REDIR_OUTPUT)
		return (1);
	if (token->type == APPEND)
		return (1);
	return (0);
}

int invalid_token(t_token *token)
{
	if (token->type == PIPE)
		return (pipe_check(token));
	else if (is_redir(token) || token->type == HERE_DOC)
	{	
		if (!redir_check(token))
			return (0);
		if (token->type != HERE_DOC && !make_redir(token))
			return (2);
		return (1);
	}
	else if (token->type == WORD || token->type == SSPACE)
		return (1);
	return (0);
}

int	valid_syntax(t_terminal *terminal, t_token **token_head)
{
	t_token	*current;
	int		error_flag;

	current = *token_head;
	while (current)
	{
		error_flag = invalid_token(current);
		if (error_flag == 0)
		{
			terminal->exit_status = 2;
			return (0);
		}
		else if (error_flag == 2)
		{
			terminal->exit_status = 1;
			return (0);
		}
		current = current->next;
	}
	return (1);
}
