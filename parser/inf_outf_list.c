/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_outf_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:07:55 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/06 19:14:30 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_infile	*create_node_infile(t_token **token)
{
	t_infile	*new_node;
	char		*word;

	word = ft_strdup("");
	new_node = ft_malloc(sizeof(t_infile));
	if (!new_node)
		return (0);
	while ((*token) && (*token)->type == WORD)
	{
		word = ft_strjoin_free(word, (*token)->token);
		(*token) = (*token)->next;
	}
	new_node->infile = word;
	new_node->next = 0;
	return (new_node);
}

void	addback_infile(t_cmd *cmd, t_token **token)
{
	t_infile	*new_node;
	t_infile	*tmp;

	if (!cmd || !token)
		return;
	new_node = create_node_infile(token);
	if (!new_node)
		return;
	if (!cmd->infile_list)
		cmd->infile_list = new_node;
	else
	{
		tmp = cmd->infile_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	cmd->infile = ft_strdup(new_node->infile);
}

t_outfile	*create_node_outfile(t_token **token, int append_flag)
{
	t_outfile	*new_node;
	char		*word;

	word = ft_strdup("");
	new_node = ft_malloc(sizeof(t_outfile));
	if (!new_node)
		return (0);
	while ((*token) && (*token)->type == WORD)
	{
		word = ft_strjoin_free(word, (*token)->token);
		(*token) = (*token)->next;
	}
	new_node->outfile = word;
	new_node->append = append_flag;
	new_node->next = 0;
	return (new_node);
}

void	addback_outfile(t_cmd *cmd, t_token **token, int append_flag)
{
	t_outfile	*new_node;
	t_outfile	*tmp;

	if (!cmd || !token)
		return;
	new_node = create_node_outfile(token, append_flag);
	if (!new_node)
		return;
	if (!cmd->outfile_list)
		cmd->outfile_list = new_node;
	else
	{
		tmp = cmd->outfile_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	cmd->outfile = ft_strdup(new_node->outfile);
	cmd->append = append_flag;
}
