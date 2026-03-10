/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_outf_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitz <kitz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:07:55 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/11 00:08:57 by kitz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_files	*create_node_files(t_token **token, int type, int append_flag)
{
	t_files		*new_node;
	char		*word;

	word = ft_strdup("");
	new_node = ft_malloc(sizeof(t_files));
	if (!new_node)
		return (0);
	while ((*token) && (*token)->type == WORD)
	{
		word = ft_strjoin_free(word, (*token)->token);
		(*token) = (*token)->next;
	}
	new_node->file = word;
	new_node->type = type;
	new_node->append = append_flag;
	new_node->next = 0;
	return (new_node);
}

void	addback_files(t_cmd *cmd, t_token **token, int type, int append_flag)
{
	t_files	*new_node;
	t_files	*tmp;

	if (!cmd || !token)
		return ;
	new_node = create_node_files(token, type, append_flag);
	if (!new_node)
		return ;
	if (!cmd->files_list)
		cmd->files_list = new_node;
	else
	{
		tmp = cmd->files_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	if (type == 0)
		cmd->infile = ft_strdup(new_node->file);
	else
	{
		cmd->outfile = ft_strdup(new_node->file);
		cmd->append = append_flag;
	}
}
