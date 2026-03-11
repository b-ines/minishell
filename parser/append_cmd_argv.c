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
#include "../builtins/builtins.h"

char	**make_argv(t_token *token, int size)
{
	char	**new_argv;
	int		i;
	char	*word;

	i = 0;
	new_argv = 0;
	new_argv = ft_malloc(sizeof(char *) * (size + 2));
	if (!new_argv)
		return (0);
	while (token && i < size)
	{
		while (token && token->type == SSPACE)
			token = token->next;
		if (!token || (token->type != WORD && token->type != SSPACE))
			break ;
		word = ft_strdup("");
		while (token && token->type == WORD)
		{
			word = ft_strjoin_free(word, token->token);
			token = token->next;
		}
		new_argv[i++] = word;
	}
	new_argv[i] = 0;
	return (new_argv);
}

static int	fill_new_words(t_token **current, char **new_argv, int i, int max)
{
	while (i < max)
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
	return (i);
}

void	append_argv(t_token **current, t_cmd *node, int size)
{
	char	**new_argv;
	int		i;

	i = 0;
	new_argv = ft_malloc((tab_size(node->argv) + size + 2) * sizeof(char *));
	if (!new_argv)
		return ;
	while (node->argv[i])
	{
		new_argv[i] = ft_strdup(node->argv[i]);
		i++;
	}
	fill_new_words(current, new_argv, i, size + tab_size(node->argv));
	ft_free_split(node->argv);
	node->argv = new_argv;
}

int	get_size(t_token *token)
{
	int	size;

	size = 0;
	while (token && (token->type == WORD || token->type == SSPACE))
	{
		if (token->type == WORD)
			size++;
		token = token->next;
	}
	return (size);
}

void	add_argv(t_token **current, t_cmd *new_node)
{
	int		size;

	size = 0;
	if (new_node == NULL)
		return ;
	if (!new_node->argv || !new_node->argv[0])
	{
		size = get_size(*current);
		new_node->argv = make_argv((*current), size);
		while ((*current) && ((*current)->type == WORD
				|| (*current)->type == SSPACE))
			(*current) = (*current)->next;
	}
	else
	{
		size = get_size(*current);
		append_argv(current, new_node, size);
	}
}
