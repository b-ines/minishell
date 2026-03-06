/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:38 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/06 19:12:48 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	fill_new_node(t_token **current, t_cmd *new_node)
{
	printf("analyse de %s type %s\n", (*current)->token , lexer_to_str((*current)->type));
	if ((*current)->type == WORD)
		add_argv(current, new_node);
	else if ((*current) && (*current)->type == APPEND)
		add_append(current, new_node);
	else if ((*current) && (*current)->type == HERE_DOC)
		add_heredoc(current, new_node);
	else if ((*current) && (*current)->type == REDIR_INPUT)
		add_redir_input(current, new_node);
	else if ((*current) && (*current)->type == REDIR_OUTPUT)
		add_redir_output(current, new_node);
	else if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}

t_cmd	*parser(t_terminal *terminal, t_token *token)
{
	t_cmd	*cmds;
	t_token	*current;
	t_cmd	*new_node;

	if (!valid_syntax(terminal, &token))
		return (0);
	current = token;
	cmds = 0;
	while (current)
	{
		new_node = create_node_cmd();
		while (current && current->type != PIPE)
			fill_new_node(&current, new_node);
		if (!current || (current && current->type == PIPE))
			ft_addback_cmd(&cmds, new_node);
		if (current)
			current = current->next;
	}
	// if (!valid_redir(terminal, token))
	// {	
	// 	terminal->exit_status = 1;
	// 	return (0);
	// }
	return (cmds);
}
