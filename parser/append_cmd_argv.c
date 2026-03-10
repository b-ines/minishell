/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_cmd_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitz <kitz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:11:23 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/11 00:09:19 by kitz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**make_argv(t_token *token, int size)
{
	char	**new_argv;
	int		i;
	t_token	*current;
	char	*word;

	i = 0;
	current = token;
	new_argv = 0;
	new_argv = ft_malloc(sizeof(char *) * (size + 2));
	if (!new_argv)
		return (0);
	while (current && i < size)
	{
		while (current && current->type == SSPACE)
			current = current->next;
		if (!current || (current->type != WORD && current->type != SSPACE))
			break ;
		word = ft_strdup("");
		while (current && current->type == WORD)
		{
			word = ft_strjoin_free(word, current->token);
			current = current->next;
		}
		new_argv[i++] = word;
	}
	new_argv[i] = 0;
	return (new_argv);
}

void	append_argv(t_token **current, t_cmd *new_node, int size)
{
	char	**new_argv;
	int		i;

	i = 0;
	new_argv = ft_malloc((tab_size(new_node->argv) + size + 2) * sizeof(char *));
	if (!new_argv)
		return ;
	while (new_node->argv[i])
	{
		new_argv[i] = ft_strdup(new_node->argv[i]);
		i++;
	}
	while (i < size + tab_size(new_node->argv))
	{
		while ((*current) && (*current)->type == SSPACE)
			(*current) = (*current)->next;
		if (!(*current) || ((*current)->type != WORD
				&& (*current)->type != SSPACE))
			break ;
		new_argv[i] = ft_strdup("");
		while ((*current) && (*current)->type == WORD)
		{
			new_argv[i] = ft_strjoin_free(new_argv[i], (*current)->token);
			(*current) = (*current)->next;
		}
		i++;
	}
	new_argv[i] = 0;
	ft_free_split(new_node->argv);
	new_node->argv = new_argv;
}

void	add_argv(t_token **current, t_cmd *new_node)
{
	int		size;
	t_token	*temp;

	size = 0;
	temp = *current;
	if (new_node == NULL)
		return ;
	if (!new_node->argv || !new_node->argv[0]) // 
	{
		while (temp && (temp->type == WORD || temp->type == SSPACE))
		{
			if (temp && temp->type == SSPACE)
				temp = temp->next;
			if (temp && temp->type == WORD)
				size++;
			if (temp)
				temp = temp->next;
		}
		new_node->argv = make_argv((*current), size);
		while ((*current) && ((*current)->type == WORD
				|| (*current)->type == SSPACE))
			(*current) = (*current)->next;
	}
	else
	{	
		while (temp && (temp->type == WORD || temp->type == SSPACE))
		{
			if (temp && temp->type == SSPACE)
				temp = temp->next;
			if (temp && temp->type == WORD)
				size++;
			if (temp)
				temp = temp->next;
		}
		append_argv(current, new_node, size);
		// while ((*current) && ((*current)->type == WORD
		// 		|| (*current)->type == SSPACE))
		// 	(*current) = (*current)->next;
	}
}
