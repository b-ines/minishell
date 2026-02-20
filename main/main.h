#ifndef MAIN_H
# define MAIN_H

typedef struct s_cmd
{
	char			**argv;
	char		 	*infile;
	char			*outfile;
	char			*here_doc_delim;
	int				append;
	struct s_cmd	*next;
} t_cmd;

typedef struct s_terminal
{
	int				exit_status;
	char			**envp;
	struct s_cmd    *cmd_blocks;
}   t_terminal;

typedef struct s_token t_token;

# include "../lexer/lexer.h"
# include "../libft/libft.h"
# include "../parser/parser.h"
# include "../expand/expand.h"
# include "../builtins/builtins.h"
# include "../execve/exec.h"
# include <signal.h>
//readline
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>

//signals.c
void	signal_init(struct sigaction *sa);

//early_parser.c
int empty_cmd(t_terminal *terminal, char *line);

#endif