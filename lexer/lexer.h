#ifndef LEXER_H
# define LEXER_H

// -----------------------------

/* Standard I/O */
#include <stdio.h>

/* Readline */
#include <readline/readline.h>
#include <readline/history.h>

/* Memory */
#include <stdlib.h>

/* Write, read, access, close, dup, pipe, etc. */
#include <unistd.h>

/* Open, flags */
#include <fcntl.h>

/* Fork, execve, exit */
#include <sys/types.h>
#include <sys/wait.h>

/* Signals */
#include <signal.h>

/* Stat, lstat, fstat */
#include <sys/stat.h>

/* Directory handling */
#include <dirent.h>

/* Errors */
#include <errno.h>
#include <string.h>

/* TTY / terminal */
#include <termios.h>
#include <sys/ioctl.h>

/* Termcap */
#include <termcap.h>

/* isatty, ttyname, ttyslot */
#include <unistd.h>

/* getenv */
#include <stdlib.h>
// ------------------------------------------------------------------

#include "../libft/libft.h"

typedef enum e_lexer {
	WORD,
	PIPE,
	REDIR_INPUT,
	REDIR_OUTPUT,
	HERE_DOC,
	APPEND,
	SSPACE
} t_lexer;

typedef struct s_token {
	char			*token;
	t_lexer			type;
	int				quote_flag; // 0 pas quoted 1 single quoted 2 double quoted
	struct s_token	*next;
	struct s_token	*prev;
} t_token;

//lexer.c
t_token	*lexer(char *line);

//lists.c
void    ft_addback(t_token **all_t, char *str, int quote_flag);

//debug.c
const char* lexer_to_str(t_lexer lexer);
void    printf_list(t_token **head);

//tokenisation.c
t_token *tokenization(char *line);

//tokenisation_utils.c
int	quote_tokenisation(t_token **token, char *line, int	quote_type, int i);
int	redir_tokenisation(t_token **token, char *line, int redir_type, int i);
int	pipe_tokenisation(t_token **token, char *line, int i);

#endif