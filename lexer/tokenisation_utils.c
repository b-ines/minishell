#include "lexer.h"

int	quote_tokenisation(t_token **token, char *line, int	quote_type, int i)
{
	int	word_len;
	int	quote_flag;

	word_len = 0;
	i++;
	if (quote_type == '"')
		quote_flag = 2;
	else if (quote_type == '\'')
		quote_flag = 1;
	while (line[i + word_len] && line[i + word_len] != quote_type)
		word_len++;
	if (!line[i + word_len])
		return (-1);
	if (word_len >= 0)
		ft_addback(token, ft_strndup(&line[i], word_len), quote_flag);
	return (word_len + 2);
}

int	redir_tokenisation(t_token **token, char *line, int redir_type, int i)
{
	int	word_len;

	word_len = 0;
	if (line [i + 1] != redir_type)
	{	
		word_len = 1;
		ft_addback(token, ft_strndup(&line[i], word_len), 0);
	}
	else if (line [i + 1] == redir_type)
	{	
		word_len = 2;
		ft_addback(token, ft_strndup(&line[i], word_len), 0);
	}
	else
		word_len = -1;
	return (word_len);
}

int	pipe_tokenisation(t_token **token, char *line, int i)
{
	ft_addback(token, ft_strndup(&line[i], 1), 0);
	return (1);
}