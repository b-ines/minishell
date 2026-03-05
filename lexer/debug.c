/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:59:06 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/05 15:59:21 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

//switch interdits a supprimer a la fin

char	*lexer_to_str(t_lexer lexer)
{
	if (lexer == WORD)
		return ("WORD");
	else if (lexer == PIPE)
		return ("PIPE");
	else if (lexer == REDIR_INPUT)
		return ("REDIR_INPUT");
	else if (lexer == REDIR_OUTPUT)
		return ("REDIR_OUTPUT");
	else if (lexer == APPEND)
		return ("APPEND");
	else if (lexer == HERE_DOC)
		return ("HERE_DOC");
	else if (lexer == SSPACE)
		return ("SSPACE");
	else
		return ("INCONNU");
}

void	printf_list(t_token **head)
{
	t_token	*current;

	if (!head || !(*head))
	{
		printf("pb de liste\n");
		return ;
	}
	current = *head;
	while (current)
	{
		printf("flag = %d | type = %s | str = %s\n", current->quote_flag,
			lexer_to_str(current->type), current->token);
		current = current->next;
	}
}
