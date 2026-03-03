/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:53:52 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/02/26 18:00:26 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "../libft/libft.h"
# include "../main/main.h"

typedef enum e_lexer {
	WORD,
	PIPE,
	REDIR_INPUT,
	REDIR_OUTPUT,
	HERE_DOC,
	APPEND,
	SSPACE
}	t_lexer;

typedef struct s_token {
	char			*token;
	t_lexer			type;
	int				quote_flag; // 0 pas quoted 1 single quoted 2 double quoted
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

//lexer.c
t_token	*lexer(t_terminal *terminal, char *line);
void	set_type(t_token **token_head);

//lists.c
void		ft_addback(t_token **all_t, char *str, int quote_flag);

//debug.c
const char	*lexer_to_str(t_lexer lexer);
void		printf_list(t_token **head);

//tokenisation.c
t_token		*tokenization(char *line);

//tokenisation_utils.c
int			quote_tokenisation(t_token **token, char *line, int quote_type, int i);
int			redir_tokenisation(t_token **token, char *line, int redir_type, int i);
int			pipe_tokenisation(t_token **token, char *line, int i);

#endif

