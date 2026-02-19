#ifndef PARSER_H
# define PARSER_H

# include "../lexer/lexer.h"

typedef struct s_cmd {
	t_token			*cmd;
	int				redir_flag;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}   t_cmd;

int valid_syntax(t_terminal *terminal, t_token **token_head);

#endif