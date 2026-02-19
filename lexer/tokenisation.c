#include "lexer.h"

int	token_delimiter(char c)
{
	if (c == '|' || c == '"' || c == '\'' || c == ' ' ||  c == '<' || c == '>')
		return (1);
	return (0);
}

int	word_tokenisation(t_token **token, char *line, int i)
{
	int	word_len;

	word_len = 0;
	while (ft_isprint(line[i + word_len]) && !token_delimiter(line[i + word_len]))
		word_len++;
	ft_addback(token, ft_strndup(&line[i], word_len), 0);
	return (word_len);
}

int	get_next_token(t_token **token, char *line, int i)
{
	if (line[i] == '"' || line[i] == '\'')
		return (quote_tokenisation(token, line, line[i], i));
	else if (line[i] == '<' || line[i] == '>')
		return (redir_tokenisation(token, line, line[i], i));
	else  if (line[i] == '|')
		return (pipe_tokenisation(token, line, i));
	else if (ft_isprint(line[i]) && !token_delimiter(line[i]))
		return (word_tokenisation(token, line, i));
	else
		return (0);
}

t_token *tokenization(char *line)
{
	int		i;
	int		word_len;
	t_token *token;

	i = 0;
	token = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			ft_addback(&token, ft_strdup(" "), 0);
			while (line[i] == ' ')
				i++;
		}
		word_len = get_next_token(&token, line, i);
		if (word_len < 0)
			return (0);
		i += word_len;	
	}
	return (token);
}
