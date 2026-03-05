/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:33 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/05 18:44:17 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*create_node_cmd(void)
{
	t_cmd	*new_node;

	new_node = ft_malloc(sizeof(t_cmd));
	if (!new_node)
		return (0);
	new_node->argv = 0;
	new_node->append = 0;
	new_node->infile = 0;
	new_node->outfile = 0;
	new_node->heredoc_list = 0;
	new_node->heredoc_fd = -1;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void	ft_addback_cmd(t_cmd **cmd_head, t_cmd *new_node)
{
	t_cmd	*last;

	if (!(*cmd_head))
	{
		*cmd_head = new_node;
		return ;
	}
	last = (*cmd_head);
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}
t_heredoc	*create_node_heredoc(t_token *token)
{
	t_heredoc	*new_node;

	new_node = ft_malloc(sizeof(t_heredoc));
	if (!new_node)
		return (0);
	new_node->heredoc_fd = -1;
	new_node->here_doc_delim = ft_strjoin(token->token, "\n");
	new_node->heredoc_quoted = token->quote_flag;
	new_node->next = 0;
	return (new_node);
}

void	addback_heredoc(t_cmd *cmd, t_token *token)
{
	t_heredoc *new_node;
	t_heredoc *tmp;

	if (!cmd || !token)
		return;
	new_node = create_node_heredoc(token);
	if (!new_node)
		return;
	if (!cmd->heredoc_list)
		cmd->heredoc_list = new_node;
	else
	{
		tmp = cmd->heredoc_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}
