#include "parser.h"

t_cmd *create_node_cmd(void)
{
	t_cmd *new_node;

	new_node = malloc(sizeof(t_cmd));
	if (!new_node)
		return (0);
	new_node->append = 0;
	new_node->here_doc_delim = 0;
	new_node->infile = 0;
	new_node->outfile = 0;
	new_node->next = 0;
	return (new_node);
}

void    ft_addback_cmd(t_cmd **cmd_head, t_cmd *new_node)
{
	t_cmd *last;

	if (!(*cmd_head))
	{
		*cmd_head = new_node;
		return ;
	}
	last = (*cmd_head);
	while (last->next)
		last = last->next;
	last->next = new_node;
}