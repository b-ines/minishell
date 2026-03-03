/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchalmel <gchalmel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:00:38 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/03 17:19:14 by gchalmel         ###   ########.fr       */
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
		if (current && current->type == SSPACE)
			current = current->next;
		word = ft_strdup("");
		if (!word)
			return (NULL);
		while (current && current->type == WORD)
		{
			word = ft_strjoin_free(word, current->token);
			if (!word)
				return (NULL);
			current = current->next;
		}
		new_argv[i++] = word;
	}
	new_argv[i] = 0;
	return (new_argv);
}

void	fill_new_node(t_token **current, t_cmd *new_node)
{
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
		if (current && !current->next && current->next->next)
			current = current->next->next;
	}
	return (cmds);
}
