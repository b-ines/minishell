#include "parser.h"

int word_at_right(t_token *token)
{
	t_token *current;

	current = token;
	if (!current->next)
		return (0);
	if (current->next->type == WORD)
		return (1);
	else
		return (0);
}

int word_at_left(t_token *token)
{
	t_token *current;

	current = token;
	if (!current->prev)
		return (0);
	if (current->prev->type == WORD)
		return (1);
	else
		return (0);
}

int	is_redir(t_token *token)
{
	if (token->type == REDIR_INPUT || token->type == REDIR_OUTPUT)
		return (1);
	if (token->type == APPEND || token->type == HERE_DOC)
		return (1);
	return (0);
}

int	pipe_check(t_token *token)
{
	if (!word_at_left(token))
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (0);
	}
	else if (!word_at_right(token) || (token->next && is_redir(token->next)))
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}

int invalid_token(t_token *token)
{
	if (token->type == PIPE)
		return (pipe_check(token));
	else if (token->type == REDIR_INPUT && is_redir(token))  
		return (-2);
	else if (token->type == REDIR_OUTPUT && word_at_right(token))  
		return (-2);
	else if (token->type == HERE_DOC && word_at_right(token))  
		return (-2);
	else if (token->type == APPEND && word_at_right(token))  
		return (-2);
	else if (token->type == WORD)
		return (0);
	else
		return (1);
}

int syntax_check(t_token **token_head)
{
	t_token *current;
	int	error_flag;

	current = *token_head;
	while (current)
	{
		error_flag = invalid_token(current); 
		if (!error_flag)
			return (0);
		current = current->next;
	}
	return (1);
}

//temp a bouger de fichier apres
void  parser(t_token **token)
{
	printf("valid syntax : %d\n", syntax_check(token));
}