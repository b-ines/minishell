/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_cmd_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:11:23 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/06 19:25:30 by inbeaumo         ###   ########.fr       */
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
	new_argv = ft_malloc(sizeof(char *) * (size + 2)); //javais commente pourquoi +2 j'ai oublie
	if (!new_argv)
		return (0);
	while (current && i < size)
	{
		if (current && current->type == SSPACE)
			current = current->next;
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

char	*append_argv(t_token **current, t_cmd *new_node, int size)
{
	char	**new_argv;
	int		i;

	i = 0;
	new_argv = ft_malloc((tab_size(new_node->argv) + size + 2) * sizeof(char *));
	if (!new_argv)
		return ;
	while (new_node->argv[i])
	{
		new_node->argv[i] = ft_strdup(new_node->argv[i]);
		i++;
	}
	new_node->argv[i] = ft_strdup(qq);
	new_env[i + 1] = 0;
	ft_free_split(env);
	if (env_flag == 0)
		terminal->envp = new_env;
	else if (env_flag == 1)
		terminal->envp_export = new_env;
}

void	add_argv(t_token **current, t_cmd *new_node)
{
	int		size;
	t_token	*temp;

	size = 1;
	temp = *current;
	if (!new_node->argv && !new_node->argv[0]) // 
	{
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
	else
	{	
		while (temp && (temp->type == WORD || temp->type == SSPACE))
		{
			if (temp && temp->next && temp->next->type == WORD
				&& temp->type == SSPACE)
				size++;
			temp = temp->next;
		}
		new_node->argv = append_argv((*current), size);
		while ((*current) && ((*current)->type == WORD
				|| (*current)->type == SSPACE))
			(*current) = (*current)->next;
	}
}
