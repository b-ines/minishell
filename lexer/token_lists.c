#include "lexer.h"

t_token *create_node(char *str, int quote_flag)
{
	t_token *new_node;

	new_node = malloc(sizeof(t_token));
	new_node->token = ft_strdup(str);
	new_node->quote_flag = quote_flag;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void    ft_addback(t_token **all_t, char *str, int quote_flag)
{
	t_token *new_node;
	t_token *last;

	new_node = create_node(str, quote_flag);
	if (!(*all_t))
	{
		*all_t = new_node;
		return ;
	}
	last = *all_t;
	while (last->next)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}