/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:50:26 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/27 15:15:01 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_argv(t_token **current, t_cmd *new_node)
{
	int		size;
	t_token	*temp;

	size = 1;
	temp = *current;
	while (temp && (temp->type == WORD || temp->type == SSPACE))
	{
		if (temp && temp->next && temp->next->type == WORD
			&& temp->type == SSPACE)
			size++;
		temp = temp->next;
	}
	new_node->argv = make_argv((*current), size);
	while ((*current) && ((*current)->type == WORD
			|| (*current)->type == SSPACE))
		(*current) = (*current)->next;
}

void	add_append(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	new_node->outfile = ft_strdup((*current)->token);
	new_node->append = 1;
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}

void	add_heredoc(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	if ((*current) && (*current)->quote_flag != 0)
		new_node->heredoc_quoted = 1;
	new_node->here_doc_delim = ft_strdup((*current)->token);
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}

void	add_redir_input(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	new_node->infile = ft_strdup((*current)->token);
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}

void	add_redir_output(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	new_node->outfile = ft_strdup((*current)->token);
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}
