#ifndef PARSER_H
# define PARSER_H

# include "../lexer/lexer.h"

typedef struct s_cmd {
	t_token			*cmd;
	int				redir_flag;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}   t_cmd;

int  parser(t_token **token);

#endif