/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:59:16 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/26 17:56:27 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int token_delimiter(char c)
{
<<<<<<< HEAD
    if (c == '|' || c == '"' || c == '\'' || c == ' ' || c == '<' || c == '>')
        return (1);
    return (0);
=======
	if (c == '|' || c == '"' || c == '\'' || c == ' ' || c == '<' || c == '>')
		return (1);
	return (0);
>>>>>>> branch_inb
}

int word_tokenisation(t_token **token, char *line, int i)
{
    int word_len;

<<<<<<< HEAD
    word_len = 0;
    while (ft_isprint(line[i + word_len]) &&
           !token_delimiter(line[i + word_len]))
        word_len++;
    ft_addback(token, ft_strndup(&line[i], word_len), 0);
    return (word_len);
=======
	word_len = 0;
	if (line[i + word_len] && line[i + word_len] == '$')
		word_len++;
	while (line[i + word_len] && ft_isprint(line[i + word_len])
		&& !token_delimiter(line[i + word_len]) && line[i + word_len] != '$')
		word_len++;
	ft_addback(token, ft_strndup(&line[i], word_len), 0);
	return (word_len);
>>>>>>> branch_inb
}

int get_next_token(t_token **token, char *line, int i)
{
<<<<<<< HEAD
    if (line[i] == '"' || line[i] == '\'')
        return (quote_tokenisation(token, line, line[i], i));
    else if (line[i] == '<' || line[i] == '>')
        return (redir_tokenisation(token, line, line[i], i));
    else if (line[i] == '|')
        return (pipe_tokenisation(token, line, i));
    else if (ft_isprint(line[i]) && !token_delimiter(line[i]))
        return (word_tokenisation(token, line, i));
    else
        return (0);
=======
	if (line[i] == '"' || line[i] == '\'')
		return (quote_tokenisation(token, line, line[i], i));
	else if (line[i] == '<' || line[i] == '>')
		return (redir_tokenisation(token, line, line[i], i));
	else if (line[i] == '|')
		return (pipe_tokenisation(token, line, i));
	else if ((ft_isprint(line[i]) && !token_delimiter(line[i])))
		return (word_tokenisation(token, line, i));
	else
		return (0);
>>>>>>> branch_inb
}

t_token	*tokenization(char *line)
{
<<<<<<< HEAD
    int i;
    int word_len;
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
=======
	int		i;
	int		word_len;
	t_token	*token;

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
>>>>>>> branch_inb
}
