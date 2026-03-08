/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:50:26 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/06 19:11:53 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_append(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	if (*current && (*current)->type == WORD)
		addback_files(new_node, current, 1, 1);
}

void	add_heredoc(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	if (*current && (*current)->type == WORD)
		addback_heredoc(new_node, current);
}

void	add_redir_input(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	if (*current && (*current)->type == WORD)
		addback_files(new_node, current, 0, 0);
}

void	add_redir_output(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	if (*current && (*current)->type == WORD)
		addback_files(new_node, current, 1, 0);
}
