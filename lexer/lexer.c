#include "lexer.h"

t_lexer get_token_type(char *token)
{
	if (ft_strncmp("", token, ft_strlen(token)) == 0)
		return (WORD);
	if (ft_strncmp("|", token, ft_strlen(token)) == 0)
		return (PIPE);
	else if (ft_strncmp("<", token, ft_strlen(token)) == 0)
		return (REDIR_INPUT);
	else if (ft_strncmp(">", token, ft_strlen(token)) == 0)
		return (REDIR_OUTPUT);
	else if (ft_strncmp(">>", token, ft_strlen(token)) == 0)
		return (APPEND);
	else if (ft_strncmp("<<", token, ft_strlen(token)) == 0)
		return (HERE_DOC);
	else if (ft_strncmp(" ", token, ft_strlen(token)) == 0)
		return (SSPACE);
	else
		return (WORD);
}

void	set_type(t_token **token_head)
{
	t_token *current;

	current = *token_head;
	while (current)
	{
		current->type = get_token_type(current->token);
		current = current->next;
	}
}

t_token	*lexer(t_terminal *terminal, char *line)
{
	t_token *token;

	token = 0;
	token = tokenization(line);
	if (!token)
	{	
		terminal->exit_status = 2;
		printf("minishell: syntax error: unclosed quote\n");
		return (0);
	}
	set_type(&token);
	return (token);
}
