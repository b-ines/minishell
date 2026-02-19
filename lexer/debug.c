#include "lexer.h"

const char* lexer_to_str(t_lexer lexer)
{
	switch(lexer)
	{
		case WORD: return "WORD";
		case PIPE: return "PIPE";
		case REDIR_INPUT: return "REDIR_INPUT";   
		case REDIR_OUTPUT: return "REDIR_OUTPUT";
		case HERE_DOC: return "HERE_DOC";
		case APPEND: return "APPEND";
		case SSPACE: return "SSPACE";
		default:    return "INCONNU";
	}
}

void    printf_list(t_token **head)
{
	t_token *current;

	if (!head || !(*head))
	{	
		printf("pb de liste\n");
		return ;
	}
	current = *head;
	while (current)
	{
		printf("flag = %d | type = %s | str = %s\n", current->quote_flag, lexer_to_str(current->type), current->token);
		current = current->next;
	}
}