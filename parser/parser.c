#include "parser.h"

char	**make_argv(t_token *token, int size)
{
	char	**new_argv;
	int	i;
	t_token *current;
	char	*word;

	i = 0;
	current = token;
	new_argv = 0;
	new_argv = malloc(sizeof(char *) * (size + 2));
	if (!new_argv)
		return (0);
	while (current && i < size)
	{
		if (current && current->type == SSPACE)
			current = current->next;
		word =  ft_strdup("");
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

void    add_argv(t_token **current, t_cmd *new_node)
{
	int size;
	t_token *temp;

	size = 1;
	temp = *current;
	while (temp && (temp->type == WORD || temp->type == SSPACE))
	{
		if (temp && temp->next && temp->next->type == WORD && temp->type == SSPACE)
			size++;
		temp = temp->next;
	}
	new_node->argv = make_argv((*current), size);
	while((*current) && ((*current)->type == WORD || (*current)->type == SSPACE))
		(*current) = (*current)->next;
}

void    add_append(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	new_node->outfile = ft_strdup((*current)->token);
	new_node->append =  1;
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}

void    add_heredoc(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	new_node->here_doc_delim = ft_strdup((*current)->token);
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}

void    add_redir_input(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	new_node->infile = ft_strdup((*current)->token);
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
}

void    add_redir_output(t_token **current, t_cmd *new_node)
{
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
	new_node->outfile = ft_strdup((*current)->token);
	(*current) = (*current)->next;
	if ((*current) && (*current)->type == SSPACE)
		(*current) = (*current)->next;
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
	t_token *current;
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
	return (cmds);
}
