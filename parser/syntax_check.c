#include "parser.h"

int word_at_right(t_token *token)
{
	t_token *current;

	current = token;
	if (!current->next)
		return (0);
	if (current->next->type == SSPACE)
		current = token->next;
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
	if (current->prev->type == SSPACE)
		current = token->prev;
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
	if (!(word_at_right(token) || (token->next && is_redir(token->next))))
	{
		printf("minishell: syntax error near unexpected token `|'\n");
		return (0);
	}
	return (1);
}
//particulierment chiant celui la pour le  < pour message 4x<=< 5x<=2 + que 5< cest <<< 
int	redir_check(t_token *token)
{
	if (word_at_right(token))
		return (1);
	else if (!token->next)
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		return (0);
	}
	// if (token->type == HERE_DOC && token->next->type == REDIR_INPUT)
	// {
	// 	printf("minishell: syntax error near unexpected token `newline'\n");
	// 	return (0);
	// }
	if (token->next->type == SSPACE && token->next->next && is_redir(token->next->next))
	{
		printf("minishell: syntax error near unexpected token `%s'\n", token->next->next->token);
		return (0);
	}
	else if (token->next->type != SSPACE && is_redir(token->next))
	{
		printf("minishell: syntax error near unexpected token `%s'\n", token->next->token);
		return (0);
	}
	return (1);
}

int invalid_token(t_token *token)
{
	if (token->type == PIPE)
		return (pipe_check(token));
	else if (is_redir(token))  
		return (redir_check(token));
	else if (token->type == WORD || token->type == SSPACE)
		return (1);
	return (0);
}

int valid_syntax(t_terminal *terminal, t_token **token_head)
{
	t_token *current;
	int	error_flag;

	current = *token_head;
	while (current)
	{
		error_flag = invalid_token(current); 
		if (!error_flag)
		{	
			terminal->exit_status = 2;
			return (0);
		}
		current = current->next;
	}
	return (1);
}